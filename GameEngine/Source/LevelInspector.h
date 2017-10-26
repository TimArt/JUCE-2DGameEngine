/*

		Displays a hierarchy of all elements present in the level(scene)
*/
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Level.h"
#include "CoreEngine.h"
#include "Inspector.h"
#include "SelectObjectButtonPropertyComponent.h"

class LevelInspector : public Component, public InspectorUpdater,
                       public Button::Listener, public ComboBox::Listener, 
					   public TextPropertyComponent::Listener, public Value::Listener
{
public:
	LevelInspector();


	~LevelInspector();

	void setCoreEngine(CoreEngine* engine);
	// JUCE GUI Callbacks ======================================================

	void updateInspector(GameModel & gameModel);
	void paint(Graphics& g) override;

	void textPropertyComponentChanged(TextPropertyComponent * component) override;

	void resized() override;

	void buttonClicked(Button * button) override;

    
	void comboBoxChanged(ComboBox *comboBoxThatHasChanged) override;

	void valueChanged(Value &value);

	void setChildrenEnabled(bool shouldBeEnabled);


	GameObject* getSelectedGameObject();
private:
    
    Label levelLabel;
    ComboBox levelComboBox;
    TextButton addLevelButton;
    TextButton removeLevelButton;
    int currentLevelIndex;
    
	CoreEngine* coreEngine;
	ToggleButton playButton;
	OwnedArray<TextButton> buttons;
	PropertyPanel propertyPanel;
	Value selectedObjectValue;
	Array<GameObject*> gameObjects;

	GameObject* selectedObject;
	Level* selectedLevel;

	Array<PropertyComponent *> levelObjGraphProperties;
	Array<PropertyComponent *> levelPhysicsProperties;
	Array<PropertyComponent *> levelAudioProperties;
	Array<PropertyComponent *> levelBackgroundProperties;
};
