from pathlib import Path


class Problem:
    def __init__(self, problem, contest_name):
        self.contest_name = contest_name
        self.name = problem[0][1:].strip()
        tags = [line for line in problem if line.startswith('- タグ')]
        if tags:
            self.tags = tags[0][5:].strip().split('、')
        else:
            self.tags = []
        level = [line for line in problem if line.startswith('- レベル')]
        if level:
            self.level = level[0][6:].strip()
        else:
            self.level = '?'

    def __str__(self):
        return '{:20}: {:60}|{}|{}'.format(self.contest_name,
                                           self.name,
                                           self.level,
                                           self.tags)


all_problems = []

for diary in Path('.').glob('*.md'):
    contest_name = diary.stem
    if contest_name == 'format':
        continue
    f = open(str(diary))
    lines = f.readlines()
    p_index = [i for i, line in enumerate(lines) if line[0] == '#']
    p_index.append(len(lines))
    for i in range(len(p_index) - 1):
        problem = Problem(lines[p_index[i]:p_index[i+1]], contest_name)
        all_problems.append(problem)


def search_tag(tag, problems=all_problems):
    return [p for p in problems if tag in p.tags]


def get_all_tags(problems=all_problems):
    all_tags = set()
    for problem in problems:
        for tag in problem.tags:
            all_tags.add(tag)
    return all_tags


if __name__ == '__main__':
    tagged_all_problems = [(tag, len(search_tag(tag))) for tag in get_all_tags()]
    tagged_all_problems.sort(key=lambda x: x[0])
    print(*search_tag('二分探索'), sep='\n')
