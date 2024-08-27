# C Program Documentation Extractor
## Overview

This project is designed to automatically extract in-code documentation from C programs, specifically focusing on comments enclosed within /* */ delimiters. The primary goal is to improve the maintainability, collaboration, and debugging process of C codebases by making the code's purpose, functionality, and implementation choices more accessible through extracted documentation.

## Problem Statement

Traditional C programming often suffers from poorly documented code, which can lead to several challenges:
  
  - Reduced Maintainability: Understanding and modifying code becomes time-consuming and error-prone without clear documentation.
  - Knowledge Silos: The knowledge of how the code works is often limited to the original developer, hindering collaboration and knowledge sharing.
  - Debugging Difficulties: Undocumented code can make the debugging process frustrating and inefficient.

This project addresses these challenges by creating a tool that extracts and organizes documentation directly from the code.

## Features

  - Automatic Extraction: The tool automatically identifies and extracts comments from C code that are enclosed within /* */ delimiters.
  - Nested Comments Handling: It correctly handles nested documentation comments to avoid misinterpretations.
  - Delimiter Skipping: The tool only extracts the content between the delimiters, ensuring that the delimiters themselves are not included in the documentation.
  - Efficiency: Designed to be efficient even when processing large codebases, ensuring quick and reliable documentation extraction.
