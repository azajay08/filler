import pygame.font
import os
import pygame

white = (245,245,245)
orange = (255, 102, 0)
p1_colour = (255, 0, 127) # pink
p2_colour = (0,238,238) # light cyan
font_path = os.path.dirname(os.path.abspath(__file__))
retro = os.path.join(font_path, 'fonts', 'Retro.ttf')
retro_font = os.path.join(font_path, 'fonts', 'filler_grad.otf')

class Score:
	"""A class that will display the score"""

	def __init__(self, filler):
		"""Init scores"""
		self.screen = filler.screen
		self.screen_rect = self.screen.get_rect()
		self.settings = filler.settings
		self.title = filler.title
		self.title_rect = self.title.title_rect
		self.grid = filler.grid

		# sep is a separator
		self.title_colour = orange
		self.sep_colour = white
		self.score_font = pygame.font.Font(retro, 60)
		self.title_font = pygame.font.Font(retro_font, 60)
		self.sep_font = pygame.font.Font(None, 60)

		self.prep_scores()

	def prep_scores(self):
		"""draw the score title"""
		score_str = "score"
		self.score_title = self.title_font.render(score_str, True,
					self.title_colour, self.settings.bg_colour)
		self.score_title_rect = self.score_title.get_rect()
		self.score_title_rect.centerx = self.title_rect.centerx
		self.score_title_rect.top = self.title_rect.bottom
		
		# Inserts a separator for scores and acts as position anchor
		sep_str = "|"
		self.sep_title = self.sep_font.render(sep_str, True,
					self.sep_colour, self.settings.bg_colour)
		self.sep_title_rect = self.sep_title.get_rect()
		self.sep_title_rect.centerx = self.score_title_rect.centerx
		self.sep_title_rect.top = self.score_title_rect.bottom + 10


	def draw_score_title(self):
		"""Draw score title to screen"""
		self.screen.blit(self.score_title, self.score_title_rect)
		self.screen.blit(self.sep_title, self.sep_title_rect)

	def draw_score(self):
		"""Print the scores for each player"""
		p1_conv = str(self.settings.p1_score)
		p1_str = "{:}".format(p1_conv)
		self.p1_score_print = self.score_font.render(p1_str, True,
								p1_colour, self.settings.bg_colour)
		self.p1_score_rect = self.p1_score_print.get_rect()
		self.p1_score_rect.right = self.sep_title_rect.left - 30
		self.p1_score_rect.centery = self.sep_title_rect.centery

		p2_conv = str(self.settings.p2_score)
		p2_str = "{:}".format(p2_conv)
		self.p2_score_print = self.score_font.render(p2_str, True,
								p2_colour, self.settings.bg_colour)
		self.p2_score_rect = self.p2_score_print.get_rect()
		self.p2_score_rect.left = self.sep_title_rect.right + 30
		self.p2_score_rect.centery = self.sep_title_rect.centery

		# Create the box to clear the score each time
		self.score_clear1 = pygame.Rect(0, 0, 150, 40)
		self.score_clear2 = pygame.Rect(0, 0, 150, 40)

		self.score_clear1.right = self.sep_title_rect.left - 30
		self.score_clear1.centery = self.sep_title_rect.centery

		self.score_clear2.left = self.sep_title_rect.right + 30
		self.score_clear2.centery = self.sep_title_rect.centery

		# Clears the score so theres no overlap
		self.screen.fill(self.settings.bg_colour, self.score_clear1)
		self.screen.fill(self.settings.bg_colour, self.score_clear2)
		# Prints the scores again
		self.screen.blit(self.p1_score_print, self.p1_score_rect)
		self.screen.blit(self.p2_score_print, self.p2_score_rect)
