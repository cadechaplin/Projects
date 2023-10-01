
from graphviz import Graph








class Graph2:
    def __init__(self):
        self.vert_list = []
        self.adj_list = []
    def __str__(self):
        out = "Edges: "
        k = len(self.vert_list) + 1

        i= 1
        j = 1
        while i < k:
            while j < k:

                out = out + str(self.vert_list[i])+ ":"+ str(self.adj_list[0][j]) + ","

                j += 1
            j = 1
            i += 1
        return out[:-1]

    def add_vertex(self, item):
        if item not in self.vert_list:
            self.vert_list.append(item)
            self.adj_list.append([])

    def add_edge(self, weight, list ):
        i = 0
        while i < len(list):
            j = 0
            while j < len(list):
                if i != j:
                    self.add_edge_helper(list[j],list[i],weight)

                j += 1
            i+= 1
    def add_edge_helper(self, v1,v2, weight):
        index = self.vert_list.index(v1)
        self.adj_list[index].append((v2, weight))
    def constructBFS(self, kevin):

        queue = [str(kevin)]
        parents = ['s']
        movie = ['s']
        i = 0
        while i < len(queue):
            queue = queue + self.findneighbors(queue, parents, movie, queue[i])
            i += 1
        self.BFS = queue
        self.BFSparents = parents
        self.BFSedges = movie
        return

    def findneighbors(self,queue, parents, movie ,vert):
        index = self.vert_list.index(vert)
        i = 0

        neighbors = []

        while i < len(self.adj_list[index]):
            if self.adj_list[index][i][0] not in queue:

                neighbors.append(self.adj_list[index][i][0])
                parents.append(vert)
                movie.append(self.adj_list[index][i][1])

            i += 1

        return neighbors


    def shortestpath(self, item):
        pathvert = []
        pathedge = []

        while item != 's' and item != self.BFS[0]:
            try:

                index = self.BFS.index(str(item))
                pathvert.append(item)
                pathedge.append(self.BFSedges[index])
                item = self.BFSparents[index]
            except:

                return
        pathvert.append(item)
        return [pathvert, pathedge]
def actorkey(dict, actor):
    for key, value in dict.items():
        if value == actor:
            return key  # output: 'key2'


def main():
    graph = Graph2()

    actors = open("actors.txt", "r", encoding="latin-1")
    movies = open("movies.txt", "r", encoding="latin-1")
    pairs = open("movie-actors.txt", "r", encoding="latin-1")
    actorsdict = {}
    for line in actors:
        actor = line
        actor = actor.split("|")

        actorsdict.update({actor[0] : actor[1][:-1]})

    moviedict = {}
    for line in movies:
        movie = line
        movie = movie.split("|")
        moviedict.update({ movie[0]: movie[1][:-1]})

    pairsdict = {}
    for line in pairs:
        pair = line.strip()
        pair = pair.split("|")

        try:
            pairsdict[pair[0]].append(pair[1])
        except:
            pairsdict.update({pair[0] : [pair[1]]})



    for actor in actorsdict:

        graph.add_vertex(actor)

    for movie in pairsdict:


        graph.add_edge(movie,pairsdict[movie])



    graph.constructBFS(actorkey(actorsdict,'Kevin Bacon'))



    find = 1
    while find != "Exit":
        print("Which actor would you like to find?(Enter \"Exit\" to exit.))")
        find = input()
        try:
            path = graph.shortestpath(actorkey(actorsdict,find))

            i = 0
            print("The Bacon number for", find, "is:", len(path[1]))
            while i < len(path[1]):

                print(actorsdict[path[0][i]], "was in ",moviedict[path[1][i]], "with",actorsdict[path[0][i+1]])
                i+= 1
            vis = Graph(format='png')

            for node in path[0]:
                vis.node(actorsdict[node])
            i = 0
            for edge in path[1]:
                vis.edge(actorsdict[path[0][i]],actorsdict[path[0][i+1]],label=moviedict[path[1][i]])

                i+= 1
            vis.render(directory='graphs', view=True).replace('\\', '/')
        except:
            if find != "Exit":
                print("Actor not connected to Kevin Bacon!")


    baconvals = 0
    nobaconcount = 0
    highestcount = 0
    record = 0
    for each in actorsdict:

        try:
            add = len(graph.shortestpath(each)[1])
            baconvals = baconvals + add
            if add > highestcount:
                record = each

                highestcount = add

        except:
            nobaconcount += 1


    print("The actor with the highest bacon count is:",actorsdict[record], "with a score of:", highestcount)
    print("The average bacon count, for actors connected to Kevin Bacon, is:", baconvals/(len(actorsdict)- nobaconcount))
    print(nobaconcount/len(actorsdict)*100, "percent of actors are not connected to Kevin Bacon!")

if __name__ == '__main__':
    main()