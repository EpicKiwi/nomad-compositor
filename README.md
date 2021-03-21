# Nomad Compositor

Multicam compositor for nomad live streaming using OpenFrameworks, FFMPEG on a RaspberryPi

## Dev Install

Download [OpenFramworks v0.11](https://openframeworks.cc/versions/v0.11.1/of_v0.11.1_linux64gcc6_release.tar.gz) and extract it's content.

Follow [OpenFrameworks install procedure on linux](https://openframeworks.cc/setup/linux-install/)

> For Raspberry pi with raspbian, download the [ARMv6 version of OpenFrameworks](https://openframeworks.cc/versions/v0.11.1/of_v0.11.1_linuxarmv6l_release.tar.gz) and follow the [Raspberry pi instructions](https://openframeworks.cc/setup/raspberrypi).

Install addons dependencies `[OFFolder]/addons` : 
* [ofxVideoRecorder](https://github.com/timscaffidi/ofxVideoRecorder)

Clone this repository inside `[OFFolder]/apps/myApps`

Copy `bin/data/config.example.xml` to `bin/data/config.xml` and configure the project to your needs

Build and run the project

```
make && make run
```