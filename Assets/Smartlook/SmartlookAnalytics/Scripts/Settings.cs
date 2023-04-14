using UnityEngine;

namespace SmartlookUnity
{
    public class Settings : ScriptableObject
    {
        public const string SettingsResourceName = "SmartlookSettings";
        
        [SerializeField]
        public string ApiKey;
        [SerializeField]
        [Range(1, 120)]
        public int FPS = 10;

        private static Settings _instance;
        public static Settings Instance => _instance ??= LoadSettings();

        public static Settings LoadSettings()
        {
            return Resources.Load(SettingsResourceName) as Settings;
        }
    }
}