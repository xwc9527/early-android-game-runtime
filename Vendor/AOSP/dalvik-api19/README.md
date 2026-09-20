# Android 4.4.4 Dalvik/libdex source baseline

These unmodified files are pinned from `platform/dalvik` tag
`android-4.4.4_r2` at https://android.googlesource.com/platform/dalvik/.
Their original paths are preserved below this directory. They are the
authoritative source reference for DEX Parser Compatibility Phase 1; they are
not compiled into the Runtime by this phase.

The API19 in-memory loading path under review is:

`dvmRawDexFileOpenArray` -> `dvmPrepareDexInMemory` -> `dexSwapAndVerify` ->
`dexFileParse` -> `dexFileSetupBasicPointers`.

Pinned SHA-256 values:

- `libdex/DexFile.cpp`: `48DBBD4DCF9E279A8D5536777313AD481D8E37DAD48FA090440BB53B4D4F6D35`
- `libdex/DexFile.h`: `FD28AB815DED143DFFF57E2BDC03C71DFCFA73EE8656F1DB127A6E2F6E869890`
- `libdex/DexSwapVerify.cpp`: `3A147B4D1F9DA86C99217113A5C119961B60161AD9C7588F708A12378217D9DA`
- `vm/RawDexFile.cpp`: `54FB5070ECA317E58AD14F6BDCE91926DDB1F2D5CB715C6CF2A25F8EC4AA0FFC`
- `vm/RawDexFile.h`: `058B180ED6EFCFCA27D7B4E0AFC7FB4FB4EAC9F7C6EE305B6B0AC9AAFAB9B2CD`
- `vm/DvmDex.cpp`: `50CDC3616C78FBECC0338167A6782A530BF2FA3EDACDB1F1F8A4F9ED826C315D`
- `vm/DvmDex.h`: `8DB8A86D0F1B700AAD3563377D5152C591A166B885872E10A1D623FFE74B938C`
- `vm/analysis/DexPrepare.cpp`: `5E0B8C4F529FCF2EEA2A439C850A740EF8070E348B1C1896CC0074A79E7D2B90`

The files retain their upstream Apache-2.0 headers. The source tag and hashes,
rather than this navigation note, define the provenance.
