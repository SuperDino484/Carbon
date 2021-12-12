#pragma once
#include "Event.h"

namespace Carbon {

	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(int xpos, int ypos)
			: m_PosX(xpos), m_PosY(ypos) {}

		EventType GetEventType() override
		{
			return EventType::WindowResize;
		}

		const char* GetName() override
		{
			return "WindowResizeEvent";
		}

		inline unsigned int GetX() const { return m_PosX; }
		inline unsigned int GetY() const { return m_PosY; }

	private:
		unsigned int m_PosX;
		unsigned int m_PosY;
	};

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}

		EventType GetEventType() override
		{
			return EventType::WindowClose;
		}

		const char* GetName() override
		{
			return "WindowCloseEvent";
		}

	};

	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(float xpos, float ypos)
			: m_PosX(xpos), m_PosY(ypos) {}

		EventType GetEventType() override
		{
			return EventType::WindowMoved;
		}

		const char* GetName() override
		{
			return "WindowMovedEvent";
		}

		inline float GetX() const { return m_PosX; }
		inline float GetY() const { return m_PosY; }

	private:
		float m_PosX;
		float m_PosY;
	};

}