#include <SFML/Graphics.hpp>
#include <iostream>
#define w1_w (float) 400
#define w1_h (float) 400
#define w2_w 200
#define w2_h 300
#define size 16

// TOOLWINDOW TOOLWINDOW TOOLWINDOW TOOLWINDOW TOOLWINDOW TOOLWINDOW TOOLWINDOW TOOLWINDOW TOOLWINDOW TOOLWINDOW TOOLWINDOW TOOLWINDOW 

class Button : public sf::Drawable { // 84, 19, 146
public:
	sf::RectangleShape rectangle;
	sf::Font font;
	sf::Text text;
	float width = w2_w / 2, height = w2_h / 3;

	Button() {
		rectangle.setSize(sf::Vector2f(width, height));
		rectangle.setPosition(width / 2, height / 2);
		rectangle.setOrigin(width / 2, height / 2);
		rectangle.setFillColor(sf::Color(84, 19, 146));
		rectangle.setOutlineColor(sf::Color(14, 19, 46));
		rectangle.setOutlineThickness(2);

		font.loadFromFile("arial.ttf");
		text.setFont(font);
		text.setCharacterSize(30);
		text.setString("-");
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	}

	void set_string(std::string s) {
		text.setString(s);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	}

	void set_text_pos(sf::Vector2f pos) {
		text.setPosition(pos);
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(rectangle);
		target.draw(text);
	}
};

class All_Buttons : public sf::Drawable {
public:
	Button button[6];
	float pos_x = button->width / 2, pos_y = button->height / 2;

	All_Buttons() {
		for (int i = 0; i < 6; i++) {
			button[i].rectangle.setPosition(pos_x, pos_y);
			button[i].set_text_pos(button[i].rectangle.getPosition());

			switch (i)
			{
			case 0: button[i].set_string("cls"); break;
			case 1: button[i].set_string("set \ncolor"); break;
			case 2: button[i].set_string("*save*"); break;
			case 3: button[i].set_string("*pbp*"); break;
			case 4: button[i].set_string("get \ncolur"); break;
			case 5: break;
			default:
				break;
			}

			if (i % 2 == 1) {
				pos_y += button->height;
				pos_x = button->width / 2;
			}
			else
			{
				pos_x += button->width;
			}

		}
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		for (int i = 0; i < 6; i++)
			target.draw(button[i]);
	}
};

// WINDOW WINDOW WINDOW WINDOW WINDOW WINDOW WINDOW WINDOW WINDOW WINDOW WINDOW WINDOW WINDOW WINDOW WINDOW 

class Brush : public sf::Drawable {
public:
	sf::CircleShape circle;
	float r = 0.01;
	Brush() {
		circle.setRadius(r);
		circle.setFillColor(sf::Color::Red);
	}

	void set_pos(sf::Vector2f pos) {
		circle.setPosition(pos);
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(circle);
	}

};

class Pixel : public sf::Drawable {
public:
	int x = 0,
		y = 0;

	sf::RectangleShape rectangle;
	Pixel(/*int size*/) {
		double width = w1_w / size, height = w1_h / size;
		rectangle.setSize(sf::Vector2f(width, height));
		rectangle.setOrigin(width / 2, height / 2);
		rectangle.setPosition(w1_w / 2, w1_h / 2);
		rectangle.setOutlineThickness(1);
		rectangle.setOutlineColor(sf::Color::Black);
	}

	int get_x() {
		return x;
	}

	int get_y() {
		return y;
	}

	void set_pos(int i, int j) {
		x = i;
		y = j;
	}

	//void koloruj

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(rectangle);
	}

};

class Pixels : public sf::Drawable {
public:
	Pixel pixel[size][size];
	float width = pixel[0][0].rectangle.getSize().x;
	float height = pixel[0][0].rectangle.getSize().y;
	float pos_x = width / 2, pos_y = height / 2;
	Pixels() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				pixel[i][j].rectangle.setPosition(pos_x, pos_y);
				pixel[i][j].set_pos(i, j);
				pos_x += width;
			}
			pos_x = width / 2;
			pos_y += height;
		}
	}
	
	// zakoloruj jezeli ten sam kolor (int x, int y, sf::Color)
	// pixel[x][y].rectangle.setFillColor();

	void clear() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				pixel[i][j].rectangle.setFillColor(sf::Color::White);
			}
		}
	}

	void set_color(int x, int y, sf::Color clr) {
		pixel[x][y].rectangle.setFillColor(clr);
	}

	void ers(int x, int y) {
		pixel[x][y].rectangle.setFillColor(sf::Color::White);
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				target.draw(pixel[i][j]);
			}
		}
	}

};

// CWINDOW CWINDOW CWINDOW CWINDOW CWINDOW CWINDOW CWINDOW CWINDOW CWINDOW CWINDOW CWINDOW CWINDOW CWINDOW 

class Cbutton : public sf::Drawable {
public:
	sf::RectangleShape rectangle;
	sf::Text text;
	sf::Font font;
	sf::Vector2f pos = sf::Vector2f(w2_w / 2, w2_h - w2_h / 100);
	Cbutton() {
		rectangle.setSize(sf::Vector2f(w2_w / 2, w2_h / 5));
		rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y);
		rectangle.setPosition(pos);

		if (!font.loadFromFile("h.ttf"))
			std::cout << 00;

		text.setFont(font);
		text.setString("Accept");
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setPosition(pos.x + pos.x / 10, pos.y - pos.y / 10);
		text.setFillColor(sf::Color::Black);
		text.setCharacterSize(25);
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(rectangle);
		target.draw(text);
	}

};

class Textfield : public sf::Drawable {
public:
	std::string str = "0";
	sf::Text text;
	sf::Font font;
	sf::RectangleShape rectangle;
	bool focus = false;
	Textfield() {
		rectangle.setSize(sf::Vector2f(w2_w / 2, w2_h / 10));
		rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
		rectangle.setFillColor(sf::Color(100, 100, 100));
		rectangle.setOutlineColor(sf::Color::Black);
		rectangle.setOutlineThickness(2);
		rectangle.setPosition(w2_w / 2, w2_h / 2);
		font.loadFromFile("arri.ttf");
		text.setFont(font);
		text.setString("");
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setFillColor(sf::Color::White);
		text.setCharacterSize(20);
		text.setPosition(rectangle.getPosition().x + text.getLocalBounds().width / 7, rectangle.getPosition().y);
		text.setOutlineThickness(2);
		text.setOutlineColor(sf::Color::Black);
	}

	void if_bigger() {
		if (atoi(str.c_str()) >= 255)
			str = "255";
	}

	void pop_str(int i) {
		if (str.length() >= 1)
			str.pop_back();
		switch (i)
		{
		case 0:
			text.setString("R: " + str); break;
		case 1:
			text.setString("G: " + str); break;
		case 2:
			text.setString("B: " + str); break;
		}
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	}

	void set_full_string(int i, std::string s) {
		str = s;
		switch (i)
		{
		case 0:
			if_bigger();
			text.setString("R: " + str); break;
		case 1:
			if_bigger();
			text.setString("G: " + str); break;
		case 2:
			if_bigger();
			text.setString("B: " + str); break;
		}

		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	}

	void set_string(int i, std::string s) {
		switch (i)
		{
		case 0:
			str += s;
			if_bigger();
			text.setString("R: " + str); break;
		case 1:
			str += s;
			if_bigger();
			text.setString("G: " + str); break;
		case 2:
			str += s;
			if_bigger();
			text.setString("B: " + str); break;
		}

		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	}

	void set_focus(int n) {
		n == 0 ? focus = true : focus = false;
	}

	void focused() {
		!focus ? rectangle.setFillColor(sf::Color(100, 100, 100)) : rectangle.setFillColor(sf::Color(60, 60, 60));

	}

	void str_pos() {
		text.setPosition(rectangle.getPosition().x + text.getLocalBounds().width / 7, rectangle.getPosition().y);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	}

	int get_par_col() {
		return atoi(str.c_str());
	}

	int get_string() {
		return atoi(str.c_str());
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(rectangle);
		target.draw(text);
	}

};

class Textfields : public sf::Drawable { // 48 to 57
public:
	Textfield t[3];
	float posx = w2_w / 2, posy = w2_h / 2.2, padding = 5;
	Textfields() {
		for (int i = 0; i < 3; i++) {
			t[i].rectangle.setPosition(posx, posy);
			t[i].str_pos();
			t[i].set_string(i, "");
			posy += padding + t->rectangle.getSize().y;
		}
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		for (int i = 0; i < 3; i++)
			target.draw(t[i]);
	}
};

class Color_rect : public sf::Drawable {
public:
	sf::RectangleShape rectangle;

	Color_rect() {
		rectangle.setSize(sf::Vector2f(w2_w / 2, w2_h / 3));
		rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
		rectangle.setOutlineColor(sf::Color::Black);
		rectangle.setOutlineThickness(2);
		rectangle.setFillColor(sf::Color::Black);
		rectangle.setPosition(w2_w / 2, w2_h / 5);
	}

	void set_color(int r, int g, int b) {
		rectangle.setFillColor(sf::Color(r, g, b));
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(rectangle);
	}
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(w1_w, w1_h), "Canvas", sf::Style::Close);
	sf::RenderWindow toolwindow(sf::VideoMode(w2_w, w2_h), "Toolbar", sf::Style::Close);
	toolwindow.setPosition(sf::Vector2i(window.getPosition().x + w1_w, window.getPosition().y));

	All_Buttons buttons;
	Pixels pixels;
	Brush brush[3];
	Cbutton cbutton;
	Color_rect crect;
	Textfields txt;

	sf::Image img;
	img.loadFromFile("br.png");
	sf::Cursor cursor;

	bool if_pressed_r = false,
		if_pressed_l = false,
		get_window = false,
		get_clr = false,
		pbp = false;

	//vector dla x i dla y 
	/*
		x) 4 8 
		y) 5 7
	
	
	*/
	while (window.isOpen() && toolwindow.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (!get_clr) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if_pressed_l = true;
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					if_pressed_r = true;
				}
			}
			else {
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
					for (int i = 0; i < size; i++) {
						for (int j = 0; j < size; j++) {
							if (brush[0].circle.getGlobalBounds().intersects(pixels.pixel[i][j].rectangle.getGlobalBounds())) {
								sf::Color p_color = pixels.pixel[i][j].rectangle.getFillColor();
								crect.set_color(p_color.r, p_color.g, p_color.b);
								txt.t[0].set_full_string(0, std::to_string(p_color.r));
								txt.t[1].set_full_string(1, std::to_string(p_color.g));
								txt.t[2].set_full_string(2, std::to_string(p_color.b));

							}
						}
					}
					get_clr = false;
					if (cursor.loadFromSystem(sf::Cursor::Arrow))
						window.setMouseCursor(cursor);

				}
			}
		}

		if (if_pressed_l) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (brush[0].circle.getGlobalBounds().intersects(pixels.pixel[i][j].rectangle.getGlobalBounds())) {
						pixels.set_color(i, j, crect.rectangle.getFillColor());
					}
				}
			}
		}

		if (if_pressed_r) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (brush[0].circle.getGlobalBounds().intersects(pixels.pixel[i][j].rectangle.getGlobalBounds())) {
						pixels.ers(i, j);
						//printed = true;
					}
				}
			}
		}

		if_pressed_r = false;
		if_pressed_l = false;

		while (toolwindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				toolwindow.close();

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				for (int i = 0; i < 6; i++) {
					if (brush[1].circle.getGlobalBounds().intersects(buttons.button[i].rectangle.getGlobalBounds())) {
						switch (i) {
						case 0:
							pixels.clear();
							break;
						case 1:
							get_window = true;
							break;
						case 2: break;
						case 3: break;
						case 4:
							get_clr = true;
							//if (cursor.loadFromPixels(img.getPixelsPtr(), sf::Vector2u(200, 200), sf::Vector2u(100,100)))
							if (cursor.loadFromSystem(sf::Cursor::Cross))
								window.setMouseCursor(cursor);
							break;
						case 5: break;
						}
					}
				}
			}
		}

		if (get_window) {
			sf::RenderWindow cwindow(sf::VideoMode(w2_w, w2_h), "Title");
			//cwindow.setPosition(sf::Vector2i(toolwindow.getPosition().x + toolwindow.getSize().x, toolwindow.getPosition().y));
			cwindow.setPosition(sf::Vector2i(window.getPosition().x - cwindow.getSize().x, window.getPosition().y));
			while (cwindow.isOpen())
			{
				while (cwindow.pollEvent(event)) {
					if (event.type == sf::Event::Closed) {
						cwindow.close();
						get_window = false;
					}

					if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
						if (brush[2].circle.getGlobalBounds().intersects(cbutton.rectangle.getGlobalBounds())) {
							get_window = false;
							cwindow.close();
						}
						for (int i = 0; i < 3; i++) {
							if (brush[2].circle.getGlobalBounds().intersects(txt.t[i].rectangle.getGlobalBounds()))
								txt.t[i].set_focus(0);
							else
								txt.t[i].set_focus(1);
						}
					}

					if (event.type == sf::Event::KeyPressed) { // 26 - 35
						if (event.key.code >= 26 && event.key.code <= 35) {
							for (int i = 0; i < 3; i++) {
								if (txt.t[i].focus) {
									std::string s = "";
									s += std::to_string((event.key.code - 26));
									txt.t[i].set_string(i, s);
								}
							}
						}
						if (event.key.code == 59) {

							for (int i = 0; i < 3; i++) {
								if (txt.t[i].focus) {
									txt.t[i].pop_str(i);
								}
							}
						}
					}
				}

				crect.set_color(txt.t[0].get_string(), txt.t[1].get_string(), txt.t[2].get_string());

				for (int i = 0; i < 3; i++) {
					txt.t[i].focused();
				}

				brush[2].set_pos(sf::Vector2f(sf::Mouse::getPosition(cwindow)));
				cwindow.clear(sf::Color(108, 104, 165));
				cwindow.draw(cbutton);
				cwindow.draw(crect);
				cwindow.draw(txt);
				cwindow.display();
			}
		}

		brush[0].set_pos(sf::Vector2f(sf::Mouse::getPosition(window)));
		brush[1].set_pos(sf::Vector2f(sf::Mouse::getPosition(toolwindow)));
		window.clear();
		toolwindow.clear();

		window.draw(pixels);
		window.draw(brush[0]);

		toolwindow.draw(buttons);
		toolwindow.draw(brush[1]);

		window.display();
		toolwindow.display();
	}

	return 0;
}