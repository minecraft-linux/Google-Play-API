# google-play-api

## Features
- gplayver Query play store apk version code
- gplaydl Download play store apk

## Usage

### Device Configs

By default the x86 32bit apk is downloaded. Use a `device.conf` to change device properties.
```
config.native_platforms = [
    armeabi-v7a
]
```
```
config.native_platforms = [
    arm64-v8a
]
```
```
config.native_platforms = [
    x86
]
```
```
config.native_platforms = [
    x86_64
]
```

### Authenticate

- Build https://github.com/minecraft-linux/playdl-signin-ui-qt then run it to login.
- playdl-signin-ui-qt
- ```
  gplaydl --interactive --device device.conf --save-auth --accept-tos
  We haven't authorized you yet. Please select your preferred login method:
  1. via login and password
  2. via access token
  3. via master token
  Please type the selected number and press enter: 2
  Please enter your access token: oauth2_4/...
  ```

### gplayver

```shell
gplayver --device device.conf --app com.mojang.minecraftpe --accept-tos
```

### gplaydl

```shell
gplaydl --device device.conf --app com.mojang.minecraftpe --accept-tos
```
