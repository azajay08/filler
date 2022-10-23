import pygame.font
import os

white = (245,245,245)
light_cyan = (0,238,238)
dark_cyan = (0,139,139)
deep_pink = (255,20,147)
dark_pink = (139,10,80)
yellow = (255, 247, 0)
purple = (155,48,255)

font_path = os.path.dirname(os.path.abspath(__file__))
retro = os.path.join(font_path, 'fonts', 'Retro.ttf')
retro_p = os.path.join(font_path, 'fonts', 'filler_grad.otf')

class Players:
	"""A class that will display the players"""

	def __init__(self, filler):
		"""Init players"""
		self.screen = filler.screen
		self.screen_rect = self.screen.get_rect()
		self.settings = filler.settings
		self.p1 = self.settings.p1
		self.p2 = self.settings.p2

		self.p_name_colour = white
		self.p1_colour = deep_pink
		self.p2_colour = light_cyan
		self.winner_colour = yellow
		self.pnum_font = pygame.font.Font(retro_p, 50)
		self.pname_font = pygame.font.Font(retro, 40)

		self.prep_players()

	def prep_players(self):
		"""Prep the players"""
		# Player 1
		p1_str = "Player.1"
		self.player1 = self.pnum_font.render(p1_str, True,
					self.p1_colour, self.settings.bg_colour)
		self.p1_rect = self.player1.get_rect()
		self.p1_rect.left = self.screen_rect.left + 60
		self.p1_rect.top = self.screen_rect.top + 300
		p1_name_str = self.p1
		self.player1_name = self.pname_font.render(p1_name_str, True,
					self.p_name_colour, self.settings.bg_colour)
		self.player1_rect = self.player1_name.get_rect()
		self.player1_rect.centery = self.p1_rect.centery + 60
		self.player1_rect.centerx = self.p1_rect.centerx
		# Player 2
		p2_str = "Player.2"
		self.player2 = self.pnum_font.render(p2_str, True,
					self.p2_colour, self.settings.bg_colour)
		self.p2_rect = self.player2.get_rect()
		self.p2_rect.right = self.screen_rect.right - 60
		self.p2_rect.top = self.screen_rect.top + 300

		p2_name_str = self.p2
		self.player2_name = self.pname_font.render(p2_name_str, True,
					self.p_name_colour, self.settings.bg_colour)
		self.player2_rect = self.player2_name.get_rect()
		self.player2_rect.centery = self.p2_rect.centery + 60
		self.player2_rect.centerx = self.p2_rect.centerx

		#player 1 winner
		winner_str = "Winner"
		self.winner_g = self.pnum_font.render(winner_str, True,
					self.winner_colour, self.settings.bg_colour)
		# Prints winner in gold
		self.p1_winner_rect = self.winner_g.get_rect()
		self.p1_winner_rect.centerx = self.p1_rect.centerx
		self.p1_winner_rect.centery = self.p1_rect.centery - 60
		# Print winner in white for flash effect
		self.winner_w = self.pnum_font.render(winner_str, True,
					white, self.settings.bg_colour)
		self.p1_winner_rect = self.winner_w.get_rect()
		self.p1_winner_rect.centerx = self.p1_rect.centerx
		self.p1_winner_rect.centery = self.p1_rect.centery - 60

		# player 2 winner
		self.p2_winner_rect = self.winner_g.get_rect()
		self.p2_winner_rect.centerx = self.p2_rect.centerx
		self.p2_winner_rect.centery = self.p2_rect.centery - 60

		self.p2_winner_rect = self.winner_w.get_rect()
		self.p2_winner_rect.centerx = self.p2_rect.centerx
		self.p2_winner_rect.centery = self.p2_rect.centery - 60

		# print draw
		draw_str = "  Draw"
		self.draw = self.pnum_font.render(draw_str, True,
					white, self.settings.bg_colour)

	def draw_players(self):
		"""draw player title and name"""
		self.screen.blit(self.player1, self.p1_rect)
		self.screen.blit(self.player1_name, self.player1_rect)
		self.screen.blit(self.player2, self.p2_rect)
		self.screen.blit(self.player2_name, self.player2_rect)
