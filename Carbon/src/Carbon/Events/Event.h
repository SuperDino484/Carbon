#pragma once

#include <functional>

namespace Carbon {

	/* Event types (may be changed in the future) */
	enum class EventType
	{
		None = 0,
		WindowResize, WindowClose, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	class Event
	{
		/* The std::function template for events */
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		virtual EventType GetEventType() = 0;
		virtual const char* GetName() = 0;

		inline bool IsHandled() const { return m_Handled; }

		template<typename T>
		bool Execute(EventFn<T> func)
		{
			/* Check if this event class is derived from the T class */
			// TODO: If this is slow change to different method
			auto e = *(reinterpret_cast<T*>(this));
			if (e.GetEventType() != this->GetEventType()) return false;
			/* Call the function after cast is successful */
			m_Handled = func(e);
			return true;
		}

	private:
		bool m_Handled;
	};

}