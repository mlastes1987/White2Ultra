# Contributing (WIP)
If you would like to contribute to this project, see below for instructions.

## Contribution Rules
- **Be nice**. We're all working together to create something great, let's also be great to each other in the process.
- ***Absolutely no leaked source code, even if it is sanitized, should be used to complete this project. __No exceptions__.*** 
- Before your changes are merged, the changes you make must be thoroughly tested to prevent regressions wherever possible, and verified against a clean build. In other words, your changes should not break the game, and should be consistent from a completely fresh build (as if one was to clone the repo for the first time and build it, or run `make clean` then build the project).

## Getting Started
The repository can be found [here](https://github.com/ds-pokemon-hacking/White2Upgrade). Setup instructions can be found [here](https://github.com/ds-pokemon-hacking/White2Upgrade/blob/main/README.md)

## Directory Structure (subject to change)
- `data`: Data that should end up in the game's ROMFS.
- `include`: dependencies and header files that are used by files in `src`.
- `pmc`: A prepatched version of [PMC](https://github.com/ds-pokemon-hacking/PMC), our dynamic code loader, along with the files that are needed to use it. **These files are for White 2, but can be supplanted with the corresponding patched ones from Black 2**. At some point, the build process will be rewritten to directly patch the ARM9 of a supplied ROM with it, rather than just replacing the ARM9 with a prepatched version.
- `src`: The source code for all of the patches. When building, these patches are compiled/assembled and linked together, creating a DLL for use with PMC.
`tools`: The tools used as part of the build process for White2Upgrade. See the `Makefile`/`*.mk` files for where they are used.
