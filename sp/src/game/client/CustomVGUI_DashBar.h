#ifndef CUSTOMVGUI_DASHBAR_H
#define CUSTOMVGUI_DASHBAR_H

#include <vgui_controls/Panel.h>

class CBasePlayer;

class CustomVGUI_DashBar : public vgui::Panel
{
public:
	CustomVGUI_DashBar(vgui::Panel* parent, const char* panelName);

	// Function to update the dash bar with the remaining cooldown time
	void UpdateDashBar(float remainingCooldown);

protected:
	// Override the paint function to draw the dash bar
	virtual void Paint() override;

private:
	float m_flRemainingCooldown; // Remaining cooldown time for dashes
};

#endif // CUSTOMVGUI_DASHBAR_H