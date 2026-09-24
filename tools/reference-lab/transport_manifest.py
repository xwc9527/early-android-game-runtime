"""Make a pinned AOSP manifest usable from a local manifest repository."""

import argparse
import xml.etree.ElementTree as ET
from pathlib import Path


FETCH_URLS = {
    "official": "https://android.googlesource.com/",
    "github": "https://github.com/aosp-mirror/",
}


def transport_manifest(source, destination, transport):
    tree = ET.parse(source)
    root = tree.getroot()
    remotes = root.findall("remote")
    if len(remotes) != 1 or remotes[0].get("name") != "aosp":
        raise ValueError("expected one AOSP remote")
    if remotes[0].get("fetch") != "..":
        raise ValueError("expected the upstream relative fetch URL")
    default = root.find("default")
    if default is None or default.get("revision") != "refs/tags/android-4.4.4_r2":
        raise ValueError("manifest is not pinned to android-4.4.4_r2")
    projects = root.findall("project")
    for project in projects:
        name = project.get("name")
        if not name or project.get("remote") not in (None, "aosp"):
            raise ValueError("unexpected project remote or name")
        if transport == "github":
            project.set("name", name.replace("/", "_"))
    remotes[0].set("fetch", FETCH_URLS[transport])
    target = Path(destination)
    target.parent.mkdir(parents=True, exist_ok=True)
    ET.indent(tree, space="  ")
    tree.write(target, encoding="utf-8", xml_declaration=True)
    return len(projects)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--source", required=True)
    parser.add_argument("--out", required=True)
    parser.add_argument("--transport", choices=sorted(FETCH_URLS), required=True)
    args = parser.parse_args()
    print(transport_manifest(args.source, args.out, args.transport))
