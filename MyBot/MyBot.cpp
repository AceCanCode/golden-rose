#include <dpp/dpp.h>

const std::string botToken = "OTUwNDg5OTYzNjg0ODM1Mzc4.YiZqwg.x88rvJYymzq8CmW9F6BSk7LrxXA";
const dpp::snowflake guildId = 950485799751782510;

int main() {
	dpp::cluster bot(botToken, dpp::i_default_intents | dpp::i_message_content); 

	bot.on_log(dpp::utility::cout_logger());

	bot.on_message_create([&bot](const dpp::message_create_t & event) {
		if (event.msg.content == "!bot-info") {
			dpp::embed Embed = dpp::embed().
				set_title("Rose Gold Bot - Information Panel").
				set_color(0xCCABAF).
				add_field(
					"Coded in:",
					"C++ and D++.",
					true
					).
				add_field(
					"Developed by:",
					"Keeperen#4744",
					true
				);

			bot.message_create(dpp::message(event.msg.channel_id, Embed).set_reference(event.msg.id));
		}
		else if (event.msg.content == "!project-info") {
			dpp::embed Embed = dpp::embed().
				set_title("Rose Gold Bot - Project Information").
				set_color(0xCCABAF).
				add_field(
					"About our project:",
					"This project is so that my Developer (Keeperen#4744), can learn D++ as well as C++. You will see various updates utiliseing some newer Discord features.",
					true
				).
				add_field(
					"Join our project:",
					"[Click here!](https://discord.gg/bfdERAxmkW)",
					true
				);

			bot.message_create(dpp::message(event.msg.channel_id, Embed).set_reference(event.msg.id));
		}
		else if (event.msg.content == "!prefix") {
			dpp::embed Embed = dpp::embed().
				set_title("Rose Gold Bot - Prefix Information").
				set_color(0xCCABAF).
				add_field(
					"Legacy Command Prefix:",
					"!",
					true
				).
				add_field(
					"Most of our more larger commands are now slash commands!",
					"Just type / and naviage to the bot's commands to view them all.",
					true
				);

			bot.message_create(dpp::message(event.msg.channel_id, Embed).set_reference(event.msg.id));
		}
	});

	bot.start(false);
	return 0;
}