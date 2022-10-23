import pygame
import pygame.font
import os

red = (255, 0, 0)
white = (255, 255, 255)
peach = (248, 118, 154)
purple = (155,48,255)
yellow = (255, 247, 0)
grey = (32, 32, 32)
pink = (255, 0 , 127)
orange = (255, 102, 0)
font_path = os.path.dirname(os.path.abspath(__file__))
retro = os.path.join(font_path, 'fonts', 'Retro.ttf')
retro_font = os.path.join(font_path, 'fonts', 'filler_font.otf')

class Title:
	"""A class that will display the title"""

	def __init__(self, filler):
		"""Init title"""
		self.screen = filler.screen
		self.screen_rect = self.screen.get_rect()
		self.settings = filler.settings

		self.title_colour = purple
		self.font = pygame.font.Font(retro_font, 150)
		self.by_font = pygame.font.Font(retro, 25)
		self.controls_font = pygame.font.Font(retro, 35)

		self.prep_title()

	def prep_title(self):
		"""prep the title"""
		title_str = "filler"
		self.title = self.font.render(title_str, True,
					self.title_colour, self.settings.bg_colour)
		self.title_rect = self.title.get_rect()
		self.title_rect.center = self.screen_rect.center
		self.title_rect.top = self.screen_rect.top + 20

		self.by = self.by_font.render(self.settings.author, True,
					white, self.settings.bg_colour)
		self.by_rect = self.by.get_rect()
		self.by_rect.topleft = self.screen_rect.topleft

		c_str = "Press 1 to 9 to change speed"
		self.controls = self.controls_font.render(c_str, True,
					white, self.settings.bg_colour)
		self.controls_rect = self.controls.get_rect()
		self.controls_rect.bottom = self.screen_rect.bottom - 15
		self.controls_rect.left = self.screen_rect.left + 15

		pause_str = "Press SPACE to pause"
		self.p_controls = self.controls_font.render(pause_str, True,
					white, self.settings.bg_colour)
		self.p_controls_rect = self.p_controls.get_rect()
		self.p_controls_rect.bottom = self.screen_rect.bottom - 15
		self.p_controls_rect.right = self.screen_rect.right - 15

		quit_str = "Press Q to quit"
		self.q_controls = self.controls_font.render(quit_str, True,
					red, self.settings.bg_colour)
		self.q_controls_rect = self.q_controls.get_rect()
		self.q_controls_rect.top = self.screen_rect.top + 15
		self.q_controls_rect.right = self.screen_rect.right - 15

	def draw_title(self):
		"""draw the title"""
		self.screen.blit(self.title, self.title_rect)
		self.screen.blit(self.by, self.by_rect)
		self.screen.blit(self.controls, self.controls_rect)
		self.screen.blit(self.p_controls, self.p_controls_rect)
		self.screen.blit(self.q_controls, self.q_controls_rect)