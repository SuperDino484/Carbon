#pragma once
#include "Event.h"

namespace Carbon {

	class KeyTypedEvent : public Event
	{
	public:
		KeyTypedEvent(int keyCode)
			: m_KeyCode(keyCode) {}

		EventType GetEventType() override
		{
			return EventType::KeyTyped;
		}

		const char* GetName() override
		{
			return "KeyTypedEvent";
		}

	private:
		int m_KeyCode;
	};

	class KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: m_KeyCode(keyCode), m_RepeatCount(repeatCount) {}

		EventType GetEventType() override
		{
			return EventType::KeyPressed;
		}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		const char* GetName() override
		{
			return "KeyPressedEvent";
		}

	private:
		int m_RepeatCount;
		int m_KeyCode;
	};

	class KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent(int keyCode)
			: m_KeyCode(keyCode) {}

		EventType GetEventType() override
		{
			return EventType::KeyReleased;
		}

		const char* GetName() override
		{
			return "KeyReleasedEvent";
		}

	private:
		int m_KeyCode;
	};

}