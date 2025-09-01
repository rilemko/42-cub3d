<a id="readme-top" name="readme-top"></a>

<!-- ------------------------------
* TITLE, DESCRIPTION & CONTACT
------------------------------ -->
# 🕹️ cub3d

<table>
    <tr>
        <th align="left" width="3333px">Score</th>
        <th align="left" width="3333px">Duration</th>
        <th align="left" width="3333px">Peer(s)</th>
    </tr>
    <tr>
        <td>✅ <b>125</b> / 100</td>
        <td>🕓 8 week(s)</td>
        <td>👷🏻 Yes</td>
    </tr>
</table>

<br>

This team project is a video game inspired by **Wolfenstein 3D**, the first true FPS in history. It's a 3D game created from a 2D map using the **RayCasting** method. Each frame is **completely drawn pixel by pixel**. As the use of **image manipulation functions is forbidden**, textures are read, modified, rendered byte-by-byte and **resized using nearest neighbor resampling** method. This teaches how to manipulate images from their bytes, as well as gaining an advanced understanding of **trigonometry**, **geometry** and **matrix calculations**.

[**⛓️ FILE : SUBJECT**](en.subject.pdf)

<br>

<!-- ------------------------------
* TABLE OF CONTENTS
------------------------------ -->
## 📋 Table of contents

- [**👀 Overview**](#readme-overview)
- [**📦 Requirements**](#readme-requirements)
- [**💾 Installation**](#readme-installation)
- [**🛠️ Makefile**](#readme-makefile)
- [**👷🏻 Collaborators**](#readme-collaborators)
- [**📄 License**](#readme-license)

<a id="readme-overview" name="readme-overview"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* OVERVIEW
------------------------------ -->
## 👀 Overview

<p align="center">
    <img src="assets/desert.gif" width="32.8%">
    <img src="assets/maze.gif" width="32.8%">
    <img src="assets/jail.gif" width="32.8%">
</p>

### Features

- Supports movement via keyboard.
- Supports rotation via keyboard and mouse.
- Supports collisions with walls and doors.
- Supports animated textures and sprites.
- Implements expandable minimap.
- Implements openable doors.
- Distance-related dynamic darkness.
- Graded coloring for floor and ceiling.
- FPS displayed in window title.
- High-precision parsing error identification.

### Keybinding

<table>
    <tr>
        <th align="left" width="2500px">Actions</th>
        <th align="left" width="5000px">QWERTY</th>
        <th align="left" width="5000px">AZERTY</th>
    </tr>
    <tr>
        <td>Move</td>
        <td><code>W</code> <code>A</code> <code>S</code> <code>D</code></td>
        <td><code>Z</code> <code>Q</code> <code>S</code> <code>D</code></td>
    </tr>
    <tr>
        <td>Rotate (keyboard)</td>
        <td><code>arrow left</code> <code>arrow right</code></td>
        <td><code>arrow left</code> <code>arrow right</code></td>
    </tr>
    <tr>
        <td>Rotate (mouse)</td>
        <td><code>mouse</code></td>
        <td><code>mouse</code></td>
    </tr>
    <tr>
        <td>Run</td>
        <td><code>R</code></td>
        <td><code>R</code></td>
    </tr>
    <tr>
        <td>Expand minimap</td>
        <td><code>M</code></td>
        <td><code>,</code></td>
    </tr>
    <tr>
        <td>Quit</td>
        <td><code>escape</code></td>
        <td><code>escape</code></td>
    </tr>
</table>

<a id="readme-requirements" name="readme-requirements"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* REQUIREMENTS
------------------------------ -->
## 📦 Requirements

```
sudo apt -y install clang-12 make cmake build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
```

<a id="readme-installation" name="readme-installation"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* INSTALLATION
------------------------------ -->
## 💾 Installation

**1. Get the project**

```
git clone https://github.com/rilemko/42-cub3d.git
```

<br>

**2. Build the project**

```
make -j$(nproc)
```

> **🔵 Info:** The `cub3d` executable will be created in the project root directory.

<br>

**3. Run the project**

```
./cub3d <configuration.cub>
```

> **🔵 Info:** Available configurations are `desert.cub`, `jail.cub` and `maze.cub`.

> **🟣 Tips:** Invalid configurations are available in the `maps/broken` directory.


<a id="readme-makefile" name="readme-makefile"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* MAKEFILE
------------------------------ -->
## 🛠️ Makefile

<table>
    <tr>
        <th align="left" width="500px">Rule</th>
        <th align="left" width="9500px">Action</th>
        </tr>
    <tr><td><code>all</code></td><td>Compile.</td></tr>
    <tr><td><code>clean</code></td><td>Delete all generated object files</td></tr>
    <tr><td><code>fclean</code></td><td>Apply <code>clean</code>, <code>lclean</code>and delete the executable.</td></tr>
    <tr><td><code>lclean</code></td><td>Apply <code>fclean</code> to all used libraries.</td></tr>
    <tr><td><code>re</code></td><td>Apply <code>fclean</code> and force recompile.</td></tr>
</table>

[**⛓️ FILE : MAKEFILE**](Makefile)

<a id="readme-collaborators" name="readme-collaborators"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* COLLABORATORS
------------------------------ -->
## 👷🏻 Collaborators

Vladimir P. - [@Vlad-PLK](https://github.com/Vlad-PLK)

<a id="readme-license" name="readme-license"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* LICENSE
------------------------------ -->
## 📄 License

This project is licensed under the terms of the **MIT** license.

[**⛓️ FILE : LICENSE**](LICENSE.md)

<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>
