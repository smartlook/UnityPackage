using UnityEngine;

namespace SmartlookUnity
{
    [DefaultExecutionOrder(-5000)]
    public class SmartlookInitializer : MonoBehaviour
    {
        [Tooltip("Start New Session")]
        public bool StartNewSession;
        [Tooltip("Start New Session And User")]
        public bool StartNewSessionAndUser;
        
        private void Awake()
        {
            var settings = Settings.Instance;
            if (string.IsNullOrEmpty(settings.ApiKey))
            {
                Debug.LogError("Smartlook: API Key is missing. Open menu \"Smartlook/Edit Settings\" and provide correct API Key.");
            }
            Smartlook.SetupAndStartRecording(new SetupOptions(settings.ApiKey, settings.FPS, StartNewSession, StartNewSessionAndUser));
        }
    }
}