// This includes:
#include "animatedsprite.h"

// Local includes:
#include "texture.h"
#include "backbuffer.h"

AnimatedSprite::AnimatedSprite()
	: m_frameSpeed(0.0f)
	, m_frameWidth(0)
	, m_timeElapsed(0.0f)
	, m_currentFrame(0)
	, m_paused(false)
	, m_loop(false)
	, m_animating(false)
{

}

AnimatedSprite::~AnimatedSprite()
{

}

bool
AnimatedSprite::Initialise(Texture& texture)
{
	m_frameWidth = 0;
	m_frameSpeed = 0;

	m_loop = false;
	m_paused = false;
	m_animating = true;

	Sprite::Initialise(texture);

	StartAnimating();

	return (true);
}

void
AnimatedSprite::AddFrame(int x)
{
	// Ex007.1: Add the x coordinate to the frame coordinate container.
	frame.push_back(x);
}

void
AnimatedSprite::Process(float deltaTime)
{
	// Ex007.1: If not paused...
	if (!IsPaused()) {
		// Ex007.1: Count the time elapsed.
		m_timeElapsed += deltaTime;
		// Ex007.1: If the time elapsed is greater than the frame speed.
		if (m_timeElapsed > m_frameSpeed) {
			m_currentFrame++;
			m_timeElapsed = 0;

		}
		if (m_currentFrame > frame.size() - 1) {
			m_currentFrame = 0;
			if (!IsLooping()) {
				Pause();
			}

		}

		// Ex007.1: If the current frame is greater than the number of frame in this animation...
		// Ex007.1: Reset to the first frame.

		// Ex007.1: Stop the animation if it is not looping...
	}

}

void
AnimatedSprite::Draw(BackBuffer& backbuffer)
{

	backbuffer.DrawAnimatedSprite(*this);
}

void
AnimatedSprite::SetFrameSpeed(float f)
{
	m_frameSpeed = f;
}

void
AnimatedSprite::SetFrameWidth(int w)
{
	m_frameWidth = w;
}

int
AnimatedSprite::GetFrameWidth()
{
	return m_frameWidth;
}

int
AnimatedSprite::GetXFrame() {
	return frame.at(m_currentFrame);
}

void
AnimatedSprite::Pause()
{
	m_paused = !m_paused;
}

bool
AnimatedSprite::IsPaused()
{
	return (m_paused);
}

bool
AnimatedSprite::IsAnimating()
{
	return (m_animating);
}

void
AnimatedSprite::StartAnimating()
{
	m_animating = true;

	m_timeElapsed = 0;
	m_currentFrame = 0;
}

bool
AnimatedSprite::IsLooping()
{
	return (m_loop);
}

void
AnimatedSprite::SetLooping(bool b)
{
	m_loop = b;
}