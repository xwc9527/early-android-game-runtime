#!/usr/bin/env python3
"""Generate immutable replay expectations from the selected real trace segment."""

import argparse
import json
from pathlib import Path


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--selection", required=True)
    parser.add_argument("--label", choices=("gloomy", "kungfoo"), required=True)
    parser.add_argument("--out", required=True)
    args = parser.parse_args()
    spec = next(x for x in json.loads(Path(args.selection).read_text())["segments"]
                if x["label"] == args.label)
    def array(values):
        return ", ".join(f"{value}u" for value in values)
    text = f"""/* Generated from archived real guest trace, not translator input. */
#ifndef AGR_ATTRIBUTION_SEGMENT_H
#define AGR_ATTRIBUTION_SEGMENT_H
#include <stdint.h>
#define AGR_ATTRIBUTION_LABEL \"{args.label}\"
#define AGR_ATTRIBUTION_INSTRUCTIONS {spec['guest_instructions_per_segment']}u
#define AGR_ATTRIBUTION_ENTRY_PC {spec['guest_pc_first']}u
#define AGR_ATTRIBUTION_POST_PC {spec['guest_pc_after']}u
#define AGR_ATTRIBUTION_ENTRY_CPSR {spec['entry_cpsr']}u
#define AGR_ATTRIBUTION_POST_CPSR {spec['post_cpsr']}u
static const uint32_t agr_attribution_entry_regs[16] = {{{array(spec['entry_registers'])}}};
static const uint32_t agr_attribution_post_regs[16] = {{{array(spec['post_registers'])}}};
static const uint32_t agr_attribution_expected_pages[] = {{{array(spec['snapshot_guest_pages'])}}};
#define AGR_ATTRIBUTION_PAGE_COUNT {len(spec['snapshot_guest_pages'])}u
#endif
"""
    Path(args.out).write_text(text)


if __name__ == "__main__":
    main()
