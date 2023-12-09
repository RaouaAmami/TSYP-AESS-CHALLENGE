<p align="center">
  <a href="" rel="noopener">
 <img src="images/challenge.png" alt="Project logo"></a>
<!-- </p> -->

<h3 align="center">TTS Training</h3>
---

<p align="center"> Welcome to the Text-to-Speech (TTS) Training Notebook. This notebook guides you through the process of training a TTS model using the GlowTTS architecture. The steps include data preparation, model configuration, training, and testing, providing a comprehensive workflow for building and evaluating a TTS model.
    <br> 
</p>

## 📝 Table of Contents

- [Overview](#overview)
- [Data Preparation](#data-preparation)
- [Training](#training)
- [Run the Tensorboard](#run-the-tensorboard)
- [Test the Model](#test-the-model)

## 📝 Overview

In this notebook, we will download data, format it for TTS, configure the training and testing runs, train a new model, and finally test the model's performance. The TTS model used is GlowTTS, and we leverage the TTS library for streamlined implementation.

## 📊 Data Preparation

To start, we need data in a specific format. We adopt the format from the LJSpeech dataset, with audio files and corresponding transcriptions in a metadata file. The dataset is organized into a specific folder structure. The notebook provides code snippets for downloading and formatting the data.

## 🚀 Training

GlowTTS is used for training the model. The notebook initializes the model training configuration, including batch size, text cleaner, use of phonemes, and other parameters. It also covers the initialization of the audio processor and tokenizer. Training samples are loaded, and the model is initialized using the GlowTTS architecture. The Trainer class provides a generic API for training TTS models with various features.

## 🚀 Run the Tensorboard

During training, Tensorboard can be utilized to monitor the model's progress. The notebook provides commands to install and run Tensorboard, allowing visualization of training metrics and sample outputs.

## ✅ Test the Model

After training, the model can be tested using the latest saved checkpoint. The notebook includes code to obtain the latest checkpoint, and a sample text is used for TTS. The generated audio can be played directly in the notebook.

## 📄 License

This project is licensed under the [MIT License](LICENSE).
