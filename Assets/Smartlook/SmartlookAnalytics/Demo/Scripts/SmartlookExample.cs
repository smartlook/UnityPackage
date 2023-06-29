using System;
using UnityEngine;
using UnityEngine.UI;

namespace SmartlookUnity.Demo.Scripts
{
    public class SmartlookExample : MonoBehaviour
    {
        // API-key must be entered for this script to work
        // Go to Smartlook -> Edit Settings to enter API-key
        // More about analytics events can be found here: https://mobile.developer.smartlook.com/v1.0/reference/unity-analytics

        private bool _timedEventStarted;

        public Button TimedEventStartButton;
        public Button TimedEventStopButton;
        public Button TimedEventCancelButton;

        private void Awake()
        {
            TimedEventStopButton.interactable = false;
            TimedEventCancelButton.interactable = false;
        }

        public void TrackCustomEvent()
        {
            Smartlook.TrackCustomEvent("MyCustomEvent");
        }

        public void NavigationEventExit()
        {
            Smartlook.TrackNavigationEvent("DemoScene", Smartlook.NavigationEventType.exit);
        }

        public void NavigationEventEnter()
        {
            Smartlook.TrackNavigationEvent("DemoScene", Smartlook.NavigationEventType.enter);
        }

        public void StartTimedEvent()
        {
            if (_timedEventStarted)
                return;
            Smartlook.StartTimedCustomEvent("TimedEvent");
            _timedEventStarted = true;
            TimedEventStartButton.interactable = false;
            TimedEventStopButton.interactable = true;
            TimedEventCancelButton.interactable = true;
        }

        public void StopTimedEvent()
        {
            if (!_timedEventStarted)
                return;
            Smartlook.StopTimedCustomEvent("TimedEvent");
            _timedEventStarted = false;
            TimedEventStartButton.interactable = true;
            TimedEventStopButton.interactable = false;
            TimedEventCancelButton.interactable = false;
        }

        public void CancelTimedEvent()
        {
            if (!_timedEventStarted)
                return;
            Smartlook.CancelTimedCustomEvent("TimedEvent", "User Canceled Timed Event");
            _timedEventStarted = false;
            TimedEventStartButton.interactable = true;
            TimedEventStopButton.interactable = false;
            TimedEventCancelButton.interactable = false;
        }
    }
}
