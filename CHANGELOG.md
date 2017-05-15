# Change Log
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/)
and this project adheres to [Semantic Versioning](http://semver.org/).

## [1.0.3] - 2017-05-15
## Added
- get_mouse_position function to Game class that takes into account scale
  factor when returning a mouse position

### Changed
- Link LICENCE.md and CHANGELOG.md from readme.
- Pass SDL_Event by reference in Game class, otherwise it's impossible to 
  access some members
- Move variable definitions from Game class CPP file to header

### Removed 
- Icon that had found its way into the project root

### Fixed
- Link to SDL_mixer in .vcxproj file was pointing to the wrong directory

## [1.0.2] - 2017-05-12
### Changed
- Ignore Documentation folder
- Move Doxyfile to project root and update file accordingly

### Removed 
- Remove generated documentation from Git repository. Generated documentation
  now provided in release.

### Fixed
- Link to v1.0.1 compare

## [1.0.1] - 2017-05-12
### Added
- CHANGELOG.md
- Change log section to README.md

### Changed
- Fix commenting for check_for_win_or_draw() in Play_state class
- Update Game class description
- Regenerate documentation
- Fix bracket indentation on Sound_resource::play() in Sound_resource class
- Update win and draw graphics with slightly better text
- Add How To Play section to README.md
- Fix naming consistency issues "Tic Tac Toe" is now "Tic-tac-toe" in source 
  and documentation
- Moved icon128.bmp outside of images folder as it isn't used by the game
- Update licence section of README.md

## [1.0.0] - 2017-05-10
### Added
- Initial release

[1.0.3]: https://github.com/chriskempson/cpp-tic-tac-toe/compare/v1.0.2...v1.0.3
[1.0.2]: https://github.com/chriskempson/cpp-tic-tac-toe/compare/v1.0.1...v1.0.2
[1.0.1]: https://github.com/chriskempson/cpp-tic-tac-toe/compare/v1.0.0...v1.0.1