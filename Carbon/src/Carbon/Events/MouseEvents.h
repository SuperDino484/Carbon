#pragma once
#include "Event.h"

namespace Carbon {

	class MouseButtonPressedEvent : public Event
	{
	public:
		MouseButtonPressedEvent(int button)
			: m_Button(button) {}

		EventType GetEventType() override
		{
			return EventType::MouseButtonPressed;
		}

		const char* GetName() override
		{
			return "MouseButtonPressed";
		}

		inline int GetButton() const { return m_Button; }

	private:
		int m_Button;
	};

	class MouseButtonReleasedEvent : public Event
	{
	public:
		MouseButtonReleasedEvent(int button)
			: m_Button(button) {}

		EventType GetEventType() override
		{
			return EventType::MouseButtonPressed;
		}

		const char* GetName() override
		{
			return "MouseButtonReleased";
		}

		inline int GetButton() const { return m_Button; }

	private:
		int m_Button;
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float xpos, float ypos)
			: m_PosX(xpos), m_PosY(ypos) {}

		EventType GetEventType() override
		{
			return EventType::MouseMoved;
		}

		const char* GetName() override
		{
			return "MouseMovedEvent";
		}

		inline float GetX() const { return m_PosX; }
		inline float GetY() const { return m_PosY; }


	private:
		float m_PosX;
		float m_PosY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xoffset, float yoffset)
			: m_OffsetX(xoffset), m_OffsetY(yoffset) {}

		EventType GetEventType() override
		{
			return EventType::MouseScrolled;
		}

		const char* GetName() override
		{
			return "MouseScrolledEvent";
		}

	private:
		float m_OffsetX;
		float m_OffsetY;
	};

}