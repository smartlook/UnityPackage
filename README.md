# Smartlook Analytics package for Unity

This package allows you to use Smartlook Analytics in your Unity projects.

## Features

* Session recording
* Tracking events

## Start guide

### 1. Install Smartlook package

This package can be installed with the Unity Package Manager.

### 2. Initialize Smartlook

Obtain your Smartlook project's Project key in [Smartlook Dashboard](https://app.smartlook.com).

Use this key to start Smartlook:

```csharp
SmartlookUnity.SetupOptionsBuilder builder = new SmartlookUnity.SetupOptionsBuilder("YOUR-SMARTLOOK-PROJECT-KEY");
SmartlookUnity.Smartlook.SetupAndStartRecording(builder.Build());
```

Track events:

```csharp
SmartlookUnity.Smartlook.TrackCustomEvent("EVENT-NAME");
```

## How to build UnityPackage

 Run following command from command line (from this folder)
'"C:\Program Files\Unity\Hub\Editor\2021.2.13f1\Editor\Unity.exe" -gvh_disable -batchmode -importPackage external-dependency-manager-1.2.172.unitypackage -exportPackage Assets SmartLook.unitypackage -quit'
