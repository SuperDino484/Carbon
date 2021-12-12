#pragma once
#include "Carbon/Layer.h"

namespace Carbon {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer()
			: Layer("ImGuiLayer") {}

		void OnAttach() override;
		void OnDetach() override;

	};

}

