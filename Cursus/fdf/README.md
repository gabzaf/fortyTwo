# 📍 FDF (Fil de Fer)

## 3D Wireframe Landscape Renderer

### 📖 Overview

FDF is a 3D wireframe modeling project that renders landscapes from .fdf files using the MiniLibX graphics library. The program reads coordinate data from a file and displays it as an interconnected mesh in an isometric projection, creating a stylized wireframe visualization.

### 🔑 Key Concepts

- Parsing .fdf files containing altitude matrices.

- 3D-to-2D projection (isometric transformation).

- Graphics programming with MiniLibX (handling windows, events, and pixel rendering).

## 🚀 Usage

### 🏗️ Compilation

`$ make`        # Builds the executable fdf

### ▶️ Execution

`$ ./fdf test_maps/42.fdf`

#### 📚 Resources

📖 MiniLibX Docs: MiniLibX Documentation

# 🧠 Technical Highlights

- Bresenham’s Algorithm: Efficient line-drawing between 3D points.

- Event Hooks: Non-blocking keyboard/mouse input handling.

- Memory Management: No leaks (verified with valgrind).

📜 Notes

- Libft functions were used for parsing. Get Next Line was used to read the data from a file.
