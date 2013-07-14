/*************************************************************************

    Atari Blasteroids hardware

*************************************************************************/

#include "machine/atarigen.h"
#include "audio/atarijsa.h"

class blstroid_state : public atarigen_state
{
public:
	enum
	{
		TIMER_IRQ_OFF = TID_ATARIGEN_LAST,
		TIMER_IRQ_ON
	};

	blstroid_state(const machine_config &mconfig, device_type type, const char *tag)
		: atarigen_state(mconfig, type, tag),
			m_jsa(*this, "jsa"),
			m_priorityram(*this, "priorityram") { }

	required_device<atari_jsa_i_device> m_jsa;
	required_shared_ptr<UINT16> m_priorityram;
	virtual void update_interrupts();
	virtual void scanline_update(screen_device &screen, int scanline);
	DECLARE_WRITE16_MEMBER(blstroid_halt_until_hblank_0_w);
	DECLARE_READ16_MEMBER(inputs_r);
	DECLARE_DRIVER_INIT(blstroid);
	TILE_GET_INFO_MEMBER(get_playfield_tile_info);
	DECLARE_MACHINE_START(blstroid);
	DECLARE_MACHINE_RESET(blstroid);
	DECLARE_VIDEO_START(blstroid);
	UINT32 screen_update_blstroid(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);

protected:
	virtual void device_timer(emu_timer &timer, device_timer_id id, int param, void *ptr);
};


/*----------- defined in video/blstroid.c -----------*/
void blstroid_scanline_update(screen_device &screen, int scanline);
