# Schore

## What is it?

Schore is a somewhat minimalistic scheduling/task manager application and is based off of [Org mode syntax](https://orgmode.org/).

## How do I install it?

### For Linux

First, you'll need to install `libsdl2-dev` and `pkg-config` from your distro's package manager.

Next, clone the repository and run

```sh
$ make main
```

to produce a binary in the `bin/` directory or

```sh
$ make run
```

to produce a binary and run the application.

### For Windows

I don't have a way of testing the build process on Windows as of now, so this is entirely blind and should be taken with a grain of salt.

First, you'll need to install developmental headers for SDL2 as well as `pkg-config`. Afterwards, you can run the makefile just like shown in the linux section.
