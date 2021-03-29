# Summary of changes


## Changes for version 1.1.11 (29 Mar 2021)

### Bug Fixes

- Updated continuous integration to:
  - Use GitHub Action to generate library documentation
  - Upload generated packages to Systelab's public Artifactory
  - Moved VS2017 configurations to work with GoogleTest 1.10.0


## Changes for version 1.1.10 (3 Sep 2020)

### Bug Fixes

- Moved to boost 1.72 to fix compilation on VS2019 configurations


## Changes for version 1.1.9 (5 Jun 2020)

### Bug Fixes

- Added configurations for VS 2019 (64 bits), with boost 1.71.0 and gtest 1.10.0


## Changes for version 1.1.8 (9 Dec 2019)

### Bug Fixes

- Linked against boost when building test utilities


## Changes for version 1.1.7 (9 Dec 2019)

### Bug Fixes

- Fixed Codacy issues
- Prepared Conan recipe to build from sources


## Changes for version 1.1.6 (15 Nov 2019)

### Bug Fixes

- Fixed issue in StubFieldValue.


## Changes for version 1.1.5 (24 Oct 2019)

### Bug Fixes

- Splitted Conan packages of this repository in two:
  - DbAdapterInterface
  - DbAdapterTestUtilities
  
  
## Changes for version 1.1.4 (10 Oct 2019)

### Bug Fixes

- Moved TestUtilities version up and fixed problems


## Changes for version 1.1.3 (9 Oct 2019)

### Bug Fixes

- Published conan packages configured as required by the Snow project


## Changes for version 1.1.2 (9 Oct 2019)

### Bug Fixes

- Unify adapter code with Snow SVN repository.


## Changes for version 1.1.1 (3 Jul 2019)

### Bug Fixes

- Improved cmake and conan configuration to link only against used dependencies.


## Changes for version 1.1.0 (9 Apr 2019)

### Enhancements

- Extended interface to support encryption


## Changes for version 1.0.0 (6 Apr 2019)

### Enhancements

- Initial version in Github (ported from internal SVN server)
