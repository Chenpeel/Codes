from manim import *

class test(Scene):
    def construct(self):
        c = Circle(fill_color=YELLOW_A,fill_opacity=1)
        s = Square(fill_color=BLUE,fill_opacity=1)
        self.play(FadeIn(c))
        self.wait()
        self.play(ReplacementTransform(c,s))
        self.wait()
        self.play(FadeOut(s))
        self.wait()