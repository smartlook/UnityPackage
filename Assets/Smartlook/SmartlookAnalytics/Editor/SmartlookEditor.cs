#if UNITY_IOS || UNITY_TVOS

using System.IO;
using UnityEditor;
using UnityEditor.Callbacks;
using UnityEditor.iOS.Xcode;
using UnityEditor.iOS.Xcode.Extensions;

namespace SmartlookUnity.Editor
{
    public partial class SmartlookEditor
    {
        private const string FRAMEWORK_TARGET_PATH = "Frameworks/Smartlook/SmartlookAnalytics/iOS"; // relative to build folder
        private const string FRAMEWORK_NAME = "Smartlook.framework";

        [PostProcessBuild(500)]
        public static void OnPostProcessBuild(BuildTarget target, string path)
        {
            string destPath = Path.Combine(FRAMEWORK_TARGET_PATH, FRAMEWORK_NAME);

            // obtain the xcode project
            string pbxProjectPath = PBXProject.GetPBXProjectPath(path);

            PBXProject project = new PBXProject();
            project.ReadFromFile(pbxProjectPath);

            string targetGuid = project.GetUnityMainTargetGuid();
 
            // add the framework to the project and enable 'Embed & Sign' for it
            string fileGuid = project.AddFile(destPath, destPath);

            project.AddFileToEmbedFrameworks(targetGuid, fileGuid);
            project.WriteToFile(pbxProjectPath);
        }
    }
}
#endif