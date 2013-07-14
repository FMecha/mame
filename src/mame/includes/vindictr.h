/*************************************************************************

    Atari Vindicators hardware

*************************************************************************/

#include "machine/atarigen.h"
#include "audio/atarijsa.h"

class vindictr_state : public atarigen_state
{
public:
	vindictr_state(const machine_config &mconfig, device_type type, const char *tag)
		: atarigen_state(mconfig, type, tag),
			m_jsa(*this, "jsa") { }

	required_device<atari_jsa_i_device> m_jsa;
	UINT8           m_playfield_tile_bank;
	UINT16          m_playfield_xscroll;
	UINT16          m_playfield_yscroll;
	virtual void update_interrupts();
	virtual void scanline_update(screen_device &screen, int scanline);
	DECLARE_READ16_MEMBER(port1_r);
	DECLARE_DRIVER_INIT(vindictr);
	TILE_GET_INFO_MEMBER(get_alpha_tile_info);
	TILE_GET_INFO_MEMBER(get_playfield_tile_info);
	DECLARE_MACHINE_START(vindictr);
	DECLARE_MACHINE_RESET(vindictr);
	DECLARE_VIDEO_START(vindictr);
	UINT32 screen_update_vindictr(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	DECLARE_WRITE16_MEMBER( vindictr_paletteram_w );
};
