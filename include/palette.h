unsigned char table_rgb[16 * 3] = {
	0x00, 0x00, 0x00, /*  0:黑 */
	0xff, 0x00, 0x00, /*  1:亮红 */
	0x00, 0xff, 0x00, /*  2:亮绿 */
	0xff, 0xff, 0x00, /*  3:亮黄 */
	0x00, 0x00, 0xff, /*  4:亮蓝 */
	0xff, 0x00, 0xff, /*  5:亮紫 */
	0x99, 0xCC, 0xFF, /*  6:天蓝 */
	0xff, 0xff, 0xff, /*  7:白 */
	0xdd, 0xdd, 0xdd, /*  8:亮灰 */
	0x84, 0x00, 0x00, /*  9:暗红 */
	0x00, 0x84, 0x00, /* 10:暗绿 */
	0xCD, 0xBE, 0x70, /* 11:暗黄 */
	0xa6, 0x9a, 0xbd, /* 12:半色 */
	0x84, 0x00, 0x84, /* 13:暗紫 */
	0xDE, 0xAB, 0x8A, /* 14:橡木色*/
	0x84, 0x84, 0x84  /* 15:暗灰 */
};
void init_palette(void)
{
	set_palette(0, 15, table_rgb);
	return;
}
void set_palette(int start, int end, unsigned char *rgb)
{
	int i, eflags;
	eflags = io_load_eflags();
	io_cli();
	// io_out8(0x03c8, start);
	// for (i = start; i <= end; i++) {
	//     io_out8(0x03c9, rgb[0] / 4);
	//     io_out8(0x03c9, rgb[1] / 4);
	//     io_out8(0x03c9, rgb[2] / 4);
	//     rgb += 3;
	// }
	// rgb-=3*color;
	//change color
	//fix
	int fix = 0;
	//only one times
	for (i = start; i <= end; i++)
	{
		if (fix >= 0)
		{
			io_out8(0x03c9, rgb[i * 3 + 0] >> fix);
			io_out8(0x03c9, rgb[i * 3 + 1] >> fix);
			io_out8(0x03c9, rgb[i * 3 + 2] >> fix);
		}
		else
		{
			io_out8(0x03c9, rgb[i * 3 + 0] << (fix*-1));
			io_out8(0x03c9, rgb[i * 3 + 1] << (fix*-1));
			io_out8(0x03c9, rgb[i * 3 + 2] << (fix*-1));
		}
	}
	io_store_eflags(eflags);
	return;
}
