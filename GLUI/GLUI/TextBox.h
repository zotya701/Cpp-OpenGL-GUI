#pragma once

#include "TextEditor.h"

namespace GLUI {

	class TextBox : public TextEditor {
	protected:
		virtual void handle_event(Event& e) override;
		virtual void draw(bool draw_background = true) override;
	public:
		// Type, position, size and border's width
		TextBox(TYPE type, float x = 0, float y = 0, float width = 100, float height = 20, float border_width = 1);
	};

	void TextBox::handle_event(Event& e) {
		float2 pos = this->get_absolute_position();
		if (e.mouse_left && e.mouse_pressed) {																			// If the user clicked
			if (pos.x < e.x && e.x < pos.x + width && pos.y < e.y && e.y < pos.y + height) {							// Inside the text box
				if (!e.mouse_covered) {																					// And it's not covered by an other component
					this->set_focus(true);																				// Set he focus to true
				}
			} else {
				this->set_focus(false);																					// Else set the focus to false
			}
		}
		if ((e.key_code == '\n' || e.key_code == '\r') && e.key_pressed && !e.active_shift && this->has_focus()) {		// If the text box has focus and the user pressed the enter (shift + enter is the new line in a text box)
			this->raise_event(this, e);																					// Raise an event
			this->set_focus(false);																						// And set the focus to false
		} else {
			TextEditor::handle_event(e);																				// Else handle the input by the text editor
		}
	}

	void TextBox::draw(bool draw_background) {
		//Component::draw(draw_background);
		TextEditor::draw(draw_background);
	}

	// Type, position, size and border's width
	TextBox::TextBox(TYPE type, float x, float y, float width, float height, float border_width) : TextEditor(type, x, y, width, height) {
		this->background_color = Color(120, 120, 120, 255);
		this->set_default_border_width(border_width);
	}

}