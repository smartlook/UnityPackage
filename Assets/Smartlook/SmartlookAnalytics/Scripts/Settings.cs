using UnityEngine;
using UnityEngine.Serialization;

namespace SmartlookUnity
{
    public class Settings: ScriptableObject
    {
        private const string SettingsResourceName = "SmartlookSettings";
        
        [FormerlySerializedAs("Key")] [SerializeField]
        public string ApiKey;
        [FormerlySerializedAs("Framerate")] [SerializeField]
        public int FPS = 10;

        private static Settings _instance;
        public static Settings Instance
        {
            get
            {
                return _instance ??= GetInstance();
            }
        }

        private static Settings GetInstance()
        {
            return Resources.Load(SettingsResourceName) as Settings;
        }
    }
}