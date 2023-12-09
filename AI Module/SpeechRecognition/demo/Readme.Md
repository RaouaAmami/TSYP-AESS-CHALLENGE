
<p align="center">
  <a href="" rel="noopener">
 <img src="images/challenge.png" alt="Project logo"></a>
<!-- </p> -->

<h3 align="center">Speech Recognition DEMO</h3>

# IEEE Aerospace & Electronic Systems Society Chapter - ESPRIT Student Branch

## Human Exploration Rover Challenge (HERC) - Speech Recognition Demo

## 📝 Table of Contents

- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
- [Contribution](#contribution)
- [License](#license)

---

## Overview

Welcome to the Human Exploration Rover Challenge (HERC) Speech Recognition Demo! This repository provides a demonstration of speech recognition. The demo showcases the installation process, library imports, model loading, and an example of transcribing a WAV file.

## Installation

Before running the notebook, ensure you have the required dependencies installed. Use the following commands to set up the environment:

```bash
!apt install libasound2-dev portaudio19-dev libportaudio2 libportaudiocpp0 ffmpeg
!pip install deepspeech==0.8.2
```

## Usage

1. Import the necessary Python libraries for audio processing and speech recognition:

    ```python
    from deepspeech import Model
    import numpy as np
    import os
    import wave
    import json
    from IPython.display import Audio, clear_output
    import librosa
    ```

2. Load the DeepSpeech model and configure language model parameters for optimal speech recognition:

    ```python
    model_file_path = 'model.pbmm'
    lm_file_path = 'model.scorer'
    beam_width = 100
    lm_alpha = 0.93
    lm_beta = 1.18

    model = Model(model_file_path)
    model.enableExternalScorer(lm_file_path)
    model.setScorerAlphaBeta(lm_alpha, lm_beta)
    model.setBeamWidth(beam_width)
    stream = model.createStream()
    ```

3. Use the provided function to read WAV files for transcription:

    ```python
    def read_wav_file(filename):
        # Implementation details...
    ```

4. Transcribe audio content using the streaming transcription function:

    ```python
    def transcribe_streaming(audio_file):
        # Implementation details...

    file_path = 'example/speech.wav'
    transcribe_streaming(file_path)
    ```

Feel free to experiment with different audio files and explore the potential applications of speech recognition in the context of the HERC project.

## Contribution

If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request. Your contributions are highly appreciated!

## License

This project is licensed under the [MIT License](LICENSE).