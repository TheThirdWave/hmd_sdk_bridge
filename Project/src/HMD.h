#ifndef __HMD_H__
#define __HMD_H__

class HMD
{
public:
	HMD();
	~HMD();

/* must inherit */
	virtual bool setup(const unsigned int framebuffer_object_left, const unsigned int framebuffer_object_right) = 0;

	virtual bool update(float *r_orientation_left, float *r_position_left, float *r_orientation_right, float *r_position_right) = 0;

	virtual bool frameReady(void) = 0;

	virtual bool reCenter(void) = 0;

	virtual void getProjectionMatrixLeft(const float nearz, const float farz, float *r_matrix) = 0;

	virtual void getProjectionMatrixRight(const float nearz, const float farz, float *r_matrix) = 0;

	virtual bool mirrorOn(unsigned int *color_object, unsigned int *width, unsigned int *height) = 0;

	virtual void mirrorOff(void) = 0;

/* generic */
	int getWidthLeft() { return this->m_width[0]; }
	int getHeightLeft() { return this->m_height[0]; }
	int getWidthRight() { return this->m_width[1]; }
	int getHeightRight() { return this->m_height[1]; }

protected:

/* must inherit */
	virtual bool isConnected(void) = 0;

	bool m_mirror_on = false;
	unsigned int m_framebuffer_object[2];
	unsigned int m_width[2];
	unsigned int m_height[2];
};

#endif /* __HMD_H__ */