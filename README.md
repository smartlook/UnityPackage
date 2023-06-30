# Smartlook Analytics package for Unity

This package allows you to use Smartlook Analytics in your Unity projects.

## Features

* Session recordings
* Event tracking
* Funnels

## Start guide

### 1. Install Smartlook Unity package

* Download the most recent package from [Releases](https://github.com/smartlook/UnityPackage/releases).
* Install the package in Unity: Assets -> Import Package -> Custom Package. Or just double click the package and import it into your project.

### 2. Initialize Smartlook

Obtain your Smartlook project's Project key in [Smartlook Dashboard](https://app.smartlook.com).

Use this key to start Smartlook:

```csharp
SmartlookUnity.SetupOptionsBuilder builder = new SmartlookUnity.SetupOptionsBuilder("YOUR-SMARTLOOK-PROJECT-KEY");
SmartlookUnity.Smartlook.SetupAndStartRecording(builder.Build());
```

### 3. Track events:

```csharp
SmartlookUnity.Smartlook.TrackCustomEvent("EVENT-NAME");
```

## Docs

You can have a look at the full API list in the [Smartlook.cs](Assets/Smartlook/SmartlookAnalytics/Scripts/Smartlook.cs), or in our [Online docs](https://mobile.developer.smartlook.com/v1.0/reference/unity-sdk-installation).

## How to build UnityPackage
### Command Line

 Run following command from command line (from this folder)
'"C:\Program Files\Unity\Hub\Editor\2021.2.13f1\Editor\Unity.exe" -gvh_disable -batchmode -importPackage external-dependency-manager-1.2.172.unitypackage -exportPackage Assets SmartLook.unitypackage -quit'
### Unity Editor
Right click on Smartlook folder in Project Window and select "Export Package ..."
Select "Smartlook" folder and "ExternalDependencyManager" folder
Click "Export"
