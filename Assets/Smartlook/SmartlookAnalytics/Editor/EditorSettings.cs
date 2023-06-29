using UnityEditor;
using UnityEngine;

namespace SmartlookUnity.Editor
{
    public static class EditorSettings
    {
        private const string SettingsResourceSuffix = ".asset";
        private const string SettingsResourceFolder = "Assets/Smartlook/SmartlookAnalytics/Resources/";
        
        [MenuItem("Smartlook/Edit Settings")]
        public static void EditSettings()
        {
            var setting = Settings.LoadSettings();
            if (setting == null)
            {
                setting = ScriptableObject.CreateInstance<Settings>();
                AssetDatabase.CreateAsset(setting, SettingsResourceFolder + Settings.SettingsResourceName + SettingsResourceSuffix);
                AssetDatabase.SaveAssets();
                AssetDatabase.Refresh();
                EditorUtility.FocusProjectWindow();
            } 
            
            Selection.activeObject = setting;
        }

        [MenuItem("GameObject/Smartlook/Initializer", false, 10)]
        [MenuItem("Smartlook/Create Initializer")]
        public static void CreateInitializer(MenuCommand menuCommand)
        {
            var go = new GameObject("Smartlook Initializer");
            go.AddComponent<SmartlookInitializer>();
            // Ensure it gets reparented if this was a context click (otherwise does nothing)
            GameObjectUtility.SetParentAndAlign(go, menuCommand.context as GameObject);
            // Register the creation in the undo system
            Undo.RegisterCreatedObjectUndo(go, "Create " + go.name);
            Selection.activeObject = go;
        }
    }
}