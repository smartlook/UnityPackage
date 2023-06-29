using UnityEngine;

namespace SmartlookUnity
{
    public class Settings : ScriptableObject
    {
        public const string SettingsResourceName = "SmartlookSettings";
        
        [SerializeField]
        [Tooltip("Project Key")]
        public string ProjectKey;
        [SerializeField]
        [Tooltip("Frames per second")]
        [Range(1, 30)]
        public int FPS = 2;

        private static Settings _instance;
        public static Settings Instance => _instance ??= LoadSettings();

        public static Settings LoadSettings()
        {
            return Resources.Load(SettingsResourceName) as Settings;
        }
    }
}