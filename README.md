# synth

An honest and experimental audio synthesis project written mostly in C++.  
This project explores programmatic sound generation and basic digital signal processing, with a focus on clarity and hackability over polish.

---

## Overview

**synth** lets you generate simple musical notes and sequences by programmatically writing raw PCM audio data to disk. The codebase is designed for learning, prototyping, and tinkering rather than full-scale production use.

- **Primary Language:** C++
- **Other Languages:** Shell, C
- **Status:** Highly experimental, incomplete, and subject to frequent change.

---

## Features

- **Note Generation:**  
  The heart of the project is generating musical notes using mathematical waveforms (mainly sine waves and chords).
- **PCM Output:**  
  Notes are written as raw PCM files, which you can play back with compatible audio software.
- **Basic DSP:**  
  Includes basic features like dampening (volume decay), distortion, and fading.
- **Chords and Harmonics:**  
  Supports simple chord and harmonic generation for richer sounds.
- **Modular Clip Structure:**  
  The `clip` class encapsulates a chunk of sound data, with methods for synthesis and effects.
- **Shell Script Automation:**  
  A provided `buildrun.sh` script compiles and runs the project in one go.

---

## Example: How It Works

The entry point is `src/main.cpp`, which creates an output file and calls `mknote` repeatedly to add notes:

```cpp
std::ofstream file("./out/out.pcm", std::ios::binary);
mknote(file, 261.63, 1000); // C4, 1 second
mknote(file, 392, 1000);    // G4, 1 second
// ...
```

Each note is created as a `clip`, with synthesis and damping applied, then written to the output file.

---

## Key Components

- `clip` class (`src/clip.cpp`, `include/clip.h`)
  - Holds the audio data for a segment.
  - Methods for sine wave generation (`addsine`), chords (`addchord`), harmonics, square waves, and more.
  - Effects: `dampen`, `linearfade`, `multiply`, and file output (`writeclip`).
- `config` class (`src/config.cpp`, `include/config.h`)
  - Manages sample rate, bit depth, and max volume.
- `main.cpp`
  - Demonstrates generating a tune by combining notes.
- `buildrun.sh`
  - Compiles all source files and runs the main program.

---

## Design Patterns

- **Object-Oriented:**  
  Audio segments are encapsulated as objects (`clip`), with clear responsibilities for generation and transformation.
- **Procedural Sequence:**  
  The main file composes music by sequencing calls to note generation functions.
- **Mathematical Synthesis:**  
  Most sound is generated via trigonometric functions (e.g., sine for pure tones).

---

## Building & Running

**Requirements:**
- C++17 or newer
- Bash shell & g++
- (Optional) Audio player that supports raw PCM files

**To build and run:**
```bash
./buildrun.sh
```
Output will be in `out/out.pcm`.

**Playing Output:**
- Use a media player that accepts raw PCM (e.g., Audacity: Import Raw, 44.1kHz, 16-bit, mono).

---

## Limitations & Honesty

- The code is rough, with many features incomplete or commented out.
- There is little error handling and no GUI.
- Functionality is focused on note and waveform generation, not complete song structures.
- Changing sample rate, bit depth, or more advanced synthesis features may require manual code edits.

---

## Directory Structure

- `src/` — C++ source files
- `include/` — Headers
- `out/` — Output directory for PCM files
- `build/` — Build directory (created by script)
- `buildrun.sh` — Build and run automation

---

## Contributing

Feedback and pull requests are welcome, but please keep in mind the experimental nature of the project.  
Expect breaking changes and rapid iteration.

---

## License

MIT License. See [LICENSE](LICENSE).

---

*This README reflects the current, honest state of the project: a code playground for digital sound, best suited for hacking, learning, and experimentation.*
