using UnityEditor;
using UnityEngine;

namespace SmartlookUnity.Editor
{
    public class EditorSettings
    {
        [MenuItem("Smartlook/Edit Settings")]
        public static void EditSettings()
        {
            Selection.activeObject = Settings.Instance;
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