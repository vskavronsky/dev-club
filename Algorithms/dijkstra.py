import math
# import heartrate
# heartrate.trace(browser=True)

graph = {'start': {'a': 6, 'b': 2}, 'a': {'end': 1}, 'b': {'a': 3, 'end': 5}, 'end': {}}
costs = {'a': 6, 'b': 2, 'end': math.inf}
parents = {'a': 'start', 'b': 'start', 'end': None}
processed = []


def _lowest_cost_node(_costs):
    lowest_cost = math.inf
    lowest_cost_node = None
    for unit in _costs:
        _cost = _costs[unit]
        if _cost < lowest_cost and unit not in processed:
            lowest_cost = _cost
            lowest_cost_node = unit
    return lowest_cost_node


def search(_point):
    node = _lowest_cost_node(costs)
    while node is not None:
        cost = costs[node]
        neighbors = graph[node]
        for n in neighbors.keys():
            new_cost = cost + neighbors[n]
            if costs[n] > new_cost:
                costs[n] = new_cost
                parents[n] = node
        processed.append(node)
        if _point == node:
            return costs[_point]
        node = _lowest_cost_node(costs)


if __name__ == '__main__':
    point = 'end'
    print(f"Travel from 'start' to '{point}' will take {search(point)} min.")
