using UnityEngine;

namespace SmartlookUnity.Demo.Scripts
{
    public class SmartlookExample : MonoBehaviour
    {
        // Project key must be entered for this script to work
        // Go to Smartlook -> Edit Settings to enter Project key
        // More about analytics events can be found here: https://mobile.developer.smartlook.com/v1.0/reference/unity-analytics

        public void TrackCustomEvent()
        {
            Smartlook.TrackCustomEvent("MyCustomEvent");
        }
    }
}
