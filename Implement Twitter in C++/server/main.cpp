#include "server.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../pages/signup_handler.hpp"
#include "../pages/login_handler.hpp"
#include "../pages/show_home_page.hpp"
#include "../pages/show_login_page.hpp"
#include "../pages/show_signup_page.hpp"
#include "../pages/logout.hpp"
#include "../pages/search_handler.hpp"
#include "../pages/like_handler.hpp"
#include "../pages/dislike_handler.hpp"
#include "../pages/rejeek_handler.hpp"
#include "../pages/more_detail_handler.hpp"

using namespace std;

int main(int argc, char **argv) {
    srand (time(NULL));
    Interface jeek_jeek_inteface;

    jeek_jeek_inteface.signup("u1", "hesam", "p1");
    jeek_jeek_inteface.signup("u2", "d2", "p2");
    vector<User*> mention_users;
    vector<string> tags; 
    tags.push_back("sina_khers");
    jeek_jeek_inteface.jeek("my first jeek!", tags, mention_users, 0);
    tags.clear();
    jeek_jeek_inteface.jeek("my second jeek!", tags, mention_users, 0);



    Server server(argc > 1 ? atoi(argv[1]) : 5000, "static/404.html");

    server.get("/global_style", new ShowPage("static/styles/global_styles.css"));

    server.get("/login", new Show_Login_Page(&jeek_jeek_inteface, "static/login.html")); 
    server.post("/login", new Login_Handler(&jeek_jeek_inteface));
    server.get("/login_style", new ShowPage("static/styles/login_style.css"));

    server.get("/login_with_error", new ShowPage("static/login_with_error.html"));
    server.get("/login_with_error_style", new ShowPage("static/styles/login_with_error_style.css"));

    server.get("/signup", new Show_Signup_Page(&jeek_jeek_inteface, "static/signup.html"));
    server.post("/signup", new Signup_Handler(&jeek_jeek_inteface));
    server.get("/signup_style", new ShowPage("static/styles/signup_style.css"));

    server.get("/signup_with_error", new ShowPage("static/signup_with_error.html"));
    server.get("/signup_with_error_style", new ShowPage("static/styles/signup_style_with_error_style.css"));

    server.get("/home", new Show_Home_Page(&jeek_jeek_inteface, "static/home.html"));
    server.get("/jeek_jeek_logo", new ShowImage("static/images/jeek_jeek_logo.png"));
    server.get("/search_logo", new ShowImage("static/images/search.png"));
    server.get("/home_style", new ShowPage("static/styles/home_styles.css"));
    server.get("/like_logo", new ShowImage("static/images/like.png"));
    server.get("/dislike_logo", new ShowImage("static/images/dislike.png"));
    server.post("/search", new Search_Handler(&jeek_jeek_inteface, "static/home.html"));
    
    server.post("/like", new Like_Handler(&jeek_jeek_inteface));
    
    server.post("/dislike", new Dislike_Handler(&jeek_jeek_inteface));
    server.post("/rejeek", new Rejeek_Handler(&jeek_jeek_inteface));

    server.post("/more_detail", new More_Detail_Handler(&jeek_jeek_inteface, "static/home.html"));
    server.get("/more_detail_style", new ShowPage("static/styles/more_details_styles.css"));

    server.post("/logout", new Logout(&jeek_jeek_inteface));

    server.run();
    return 0;
}
