// vasmak74.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <string>
#include <iostream>
#include <algorithm>
#include <memory>

class Text {
protected:
    std::string href = "ya.ru";

public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
    virtual ~Text() = default;
};

class DecoratedText : public Text {
protected:
    explicit DecoratedText(std::shared_ptr<Text> text) : text_(text) {}
    std::shared_ptr<Text> text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const override {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const override {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const override {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const override {
        std::string reversed_data = data;
        std::reverse(reversed_data.begin(), reversed_data.end());
        text_->render(reversed_data);
    }
};

class Link : public DecoratedText {
public:
    explicit Link(std::shared_ptr<Text> text) : DecoratedText(text) {}

    void render(const std::string& data) const override {
        std::cout << "<a href=" << href << ">";
        text_->render(data);
        std::cout << "</a>";
    }

    void render(const std::string& href, const std::string& data) const {
        std::cout << "<a href=" << href << ">";
        text_->render(data);
        std::cout << "</a>";
    }
    };

int main() {
    auto text_block = std::make_shared<ItalicText>(std::make_shared<BoldText>(std::make_shared<Text>()));   
    text_block->render("Hello world!");
    std::cout << std::endl;

    
    auto paragraph = std::make_shared<Paragraph>(std::make_shared <Text>());
    paragraph->render("Hello world");
    std::cout << std::endl;    

    auto reversed = std::make_shared<Reversed>(std::make_shared <Text>());
    reversed->render("Hello world");
    std::cout << std::endl;  

    auto link_1 = std::make_shared<Link>(std::make_shared<Text>());
    link_1->render("Hello world");
    std::cout << std::endl;

    auto link_2 = std::make_shared<Link>(std::make_shared <Text>());
    link_2->render("netology.ru", "Hello world");
    std::cout << std::endl;    

    auto text_format_1 = std::make_shared<ItalicText>(std::make_shared<BoldText>(std::make_shared<Paragraph>(std::make_shared<Reversed>(std::make_shared<Text>()))));
    text_format_1->render("Hello world!");
    std::cout << std::endl;

    auto text_format_2 = std::make_shared<Link>(std::make_shared<ItalicText>(std::make_shared<BoldText>(std::make_shared<Paragraph>(std::make_shared<Text>()))));
    text_format_2->render("netology.ru", "Hello world!");

    std::cout << "\n\n\nGood day!\n";
    return 0;
}




/* 
// old code
//
class Text {
  protected:
    std::string href = "ya.ru";

  public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};

class DecoratedText : public Text {
  public:
    Text* text_;
    explicit DecoratedText(Text* text) : text_(text) {}
    
};

class ItalicText : public DecoratedText {
  public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const override {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
  public:
    explicit BoldText(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const override {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
  public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const override {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
  public:
    explicit Reversed(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const override {
        std::string reversed_data = data;
        std::reverse(reversed_data.begin(), reversed_data.end());
        text_->render(reversed_data);
    }
};

class Link : public DecoratedText {
  public:
    explicit Link(Text* text) : DecoratedText(text) {}    

    void render(const std::string& data) const override {
        std::cout << "<a href=" << href << ">";
        text_->render(data);
        std::cout << "</a>";
    }
    void render(const std::string& href, const std::string& data) const {
        std::cout << "<a href=" << href << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};


int main() {

    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world!");
    std::cout << std::endl;

    auto paragraph = new Paragraph(new Text());
    paragraph->render("Hello world");
    std::cout << std::endl;

    auto reversed = new Reversed(new Text());
    reversed->render("Hello world");
    std::cout << std::endl;

    auto link_1 = new Link(new Text());
    link_1->render("Hello world");
    std::cout << std::endl;

    auto link_2 = new Link(new Text());
    link_2->render("netology.ru", "Hello world");
    std::cout << std::endl;    

    auto text_format_1 = new ItalicText(new BoldText(new Paragraph(new Reversed(new Text()))));
    text_format_1->render("Hello world!");
    std::cout << std::endl;

    auto text_format_2 = new Link(new ItalicText(new BoldText(new Paragraph(new Text()))));
    text_format_2->render("netology.ru", "Hello world!");

    std::cout << "\n\n\nGood day!\n";
    return 0;
}
*/


