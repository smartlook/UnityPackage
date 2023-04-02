using UnityEditor;
using UnityEngine;

namespace SmartlookUnity
{
    public class Settings: ScriptableObject
    {
        private const string SettingsResourceName = "SmartlookSettings";
        private const string SettingsResourceSuffix = ".asset";
        private const string SettingsResourceFolder = "Assets/Smartlook/SmartlookAnalytics/Resources/";
        
        [SerializeField]
        public string ApiKey;
        [SerializeField]
        [Range(1, 120)]
        public int FPS = 10;

        public static Settings Instance => GetInstance();

        private static Settings GetInstance()
        {
            var setting = Resources.Load(SettingsResourceName) as Settings;
            if (setting != null) 
                return setting;
            
            setting = CreateInstance<Settings>();
            AssetDatabase.CreateAsset(setting, SettingsResourceFolder + SettingsResourceName + SettingsResourceSuffix);
            AssetDatabase.SaveAssets();
            AssetDatabase.Refresh();
            EditorUtility.FocusProjectWindow();
            return setting;
        }
    }
}