import sys
import pygame
import os
from time import sleep
from score import Score
from grid import Grid
from pieces import Piece
from players import Players
from settings import Settings
from title import Title

white = (255, 255, 255)
orange = (255, 102, 0)

clock = pygame.time.Clock()

font_path = os.path.dirname(os.path.abspath(__file__))
retro = os.path.join(font_path, 'fonts', 'Retro.ttf')


class Filler:

	def __init__(self):
		pygame.init()
		pygame.mixer.init()
		self.settings = Settings()
		self.screen = pygame.display.set_mode((
			self.settings.screen_width, self.settings.screen_height))
		pygame.display.set_caption("FILLER")

		self.title = Title(self)
		self.player = Players(self)
		self.grid = Grid(self)
		self.score = Score(self)
		self.piece = Piece(self)
		self.screen.fill(self.settings.bg_colour)
		self.title.draw_title()
		self.score.draw_score_title()
		self.player.draw_players()

	def run_game(self):
		pygame.mixer.music.play(-1)
		while True:
			self._check_events()
			if 'Plateau' in self.settings.line:
				self.grid.draw_board()
				self.score.draw_score()
			self.settings.line = sys.stdin.readline().rstrip('\n')
			if 'Piece' in self.settings.line:
				self.piece.draw_piece()
			if 'fin' in self.settings.line:
				self.settings.line = self.settings.line.split(' ')
				p1_score = int(self.settings.line[3])
				self.settings.line = sys.stdin.readline().rstrip('\n').split(' ')
				p2_score = int(self.settings.line[3])
				if p1_score == p2_score:
					self.screen.blit(self.player.draw, self.player.p1_winner_rect)
					self.screen.blit(self.player.draw, self.player.p2_winner_rect)
				elif p1_score > p2_score:
					self.screen.blit(self.player.winner_g, self.player.p1_winner_rect)
				else:
					self.screen.blit(self.player.winner_g, self.player.p2_winner_rect)

			clock.tick(self.settings.fps)
			pygame.display.update()
			pygame.time.delay(int(self.settings.delay))

	def redraw_consts(self):
		"""function to re draw the titles/scores after they have been
			covered for the pause
		"""
		self.title.draw_title()
		self.score.draw_score_title()
		self.screen.blit(self.score.p1_score_print, self.score.p1_score_rect)
		self.screen.blit(self.score.p2_score_print, self.score.p2_score_rect)

	def pause_game(self):
		"""Function that pauses the game"""
		#pause string
		pause_font = pygame.font.Font(retro, 120)
		pause_str = pause_font.render("PAUSED", True, white)
		pause_str_rect = pause_str.get_rect()
		pause_str_rect.centerx = self.score.score_title_rect.centerx
		pause_str_rect.centery = self.score.score_title_rect.centery + 25
		# Box to to clear surface for pause string
		clear = pygame.Surface((500, 120))
		clear.fill(self.settings.bg_colour)
		self.screen.blit(clear, pause_str_rect)
		self.screen.blit(pause_str, pause_str_rect)
		pygame.display.update()
		paused = True
		while paused:
			for event in pygame.event.get():
				if event.type == pygame.KEYDOWN:
					if event.key == pygame.K_q:
						pygame.quit()
						exit()
					if event.key == pygame.K_SPACE:
						paused = False
						self.screen.blit(clear, pause_str_rect)
						self.redraw_consts()
						pygame.display.update()
				if event.type == pygame.QUIT:
					pygame.quit()
					exit()

	def _check_events(self):
		"""Function that check events in the program"""
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				sys.exit()
			elif event.type == pygame.KEYDOWN:
				if event.key == pygame.K_q:
					sys.exit()
				#check buttons or speed
				if event.key == pygame.K_1:
					self.settings.delay = 300
				if event.key == pygame.K_2:
					self.settings.delay = 200
				if event.key == pygame.K_3:
					self.settings.delay = 100
				if event.key == pygame.K_4:
					self.settings.delay = 75
				if event.key == pygame.K_5:
					self.settings.delay = 50
				if event.key == pygame.K_6:
					self.settings.delay = 25
				if event.key == pygame.K_7:
					self.settings.delay = 10
				if event.key == pygame.K_8:
					self.settings.delay = 1
				if event.key == pygame.K_9:
					self.settings.delay = 0.000001
				if event.key == pygame.K_SPACE:
					self.pause_game()
				

if __name__ == '__main__':
	filler = Filler()
	filler.run_game()
