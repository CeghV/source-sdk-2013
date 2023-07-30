#include "CustomVGUI_DashBar.h"
#include <vgui/IVGui.h>
#include <vgui/ISurface.h>
#include "c_baseplayer.h" // Include the header for CBasePlayer (adjust the header name based on your project's codebase)

CustomVGUI_DashBar::CustomVGUI_DashBar(vgui::Panel* parent, const char* panelName)
	: vgui::Panel(parent, panelName)
{
	m_flRemainingCooldown = 0.0f;
	SetVisible(false); // Hide the dash bar by default
}

void CustomVGUI_DashBar::UpdateDashBar(float remainingCooldown)
{
	m_flRemainingCooldown = remainingCooldown;
	SetVisible(true); // Show the dash bar
}

void CustomVGUI_DashBar::Paint()
{
	int width = GetWide();
	int height = GetTall();

	vgui::surface()->DrawSetColor(255, 0, 0, 255); // Red color (adjust as needed)
	vgui::surface()->DrawFilledRect(0, 0, width, height);

	float cooldownPercent = m_flRemainingCooldown / MAX_DASH_COOLDOWN; // Assuming MAX_DASH_COOLDOWN is the maximum cooldown time
	int barWidth = static_cast<int>(width * (1.0f - cooldownPercent));

	vgui::surface()->DrawSetColor(0, 255, 0, 255); // Green color (adjust as needed)
	vgui::surface()->DrawFilledRect(barWidth, 0, width, height);
}