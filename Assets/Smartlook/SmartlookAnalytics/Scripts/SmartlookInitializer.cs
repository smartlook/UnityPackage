using UnityEngine;

namespace SmartlookUnity
{
    [DefaultExecutionOrder(-5000)]
    public class SmartlookInitializer : MonoBehaviour
    {
        [Tooltip("Reset Session")]
        public bool StartNewSession;
        [Tooltip("Reset User")]
        public bool StartNewSessionAndUser;
        
        private void Awake()
        {
            var settings = Settings.Instance;
            if (settings == null)
            {
                Debug.LogError("Smartlook: Settings file missing. Open menu \"Smartlook/Edit Settings\" and provide desired settings");
                return;  
            }
            if (string.IsNullOrEmpty(settings.ProjectKey))
            {
                Debug.LogError("Smartlook: Project Key is missing. Open menu \"Smartlook/Edit Settings\" and provide correct Project Key.");
                return;
            }
            Smartlook.SetupAndStartRecording(new SetupOptions(settings.ProjectKey, settings.FPS, StartNewSession, StartNewSessionAndUser));
        }
    }
}