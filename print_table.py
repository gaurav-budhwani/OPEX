import re
import sys

def convert_action(action):
    """Convert Bison verbose action to standard SLR(1) table notation."""
    m = re.match(r'shift, and go to state (\d+)', action)
    if m:
        return 's' + m.group(1)
    m = re.match(r'reduce using rule (\d+)', action)
    if m:
        return 'r' + m.group(1)
    if action.strip() == 'accept':
        return 'acc'
    return action

def generate_parsing_table(output_file):
    with open(output_file, 'r') as f:
        lines = f.readlines()

    table = {}
    terminals = set()
    non_terminals = set()

    current_state = -1
    in_state = False

    for line in lines:
        line = line.strip()
        m = re.match(r'^[Ss]tate (\d+)$', line)
        if m:
            current_state = int(m.group(1))
            table[current_state] = {}
            in_state = True
            continue

        if not in_state:
            continue

        if not line or line.startswith('//') or 'shift/reduce' in line or 'reduce/reduce' in line:
            continue

        # Skip grammar item lines (e.g. "19 Type: TOK_ID .")
        if re.match(r'^\d', line):
            continue

        # Skip bracketed/suppressed conflict actions (e.g. "[reduce using rule 62 (LValue)]")
        if line.startswith('['):
            continue

        m = re.match(r'^(\S+)\s+(.+)$', line)
        if m:
            sym, action = m.groups()
            if sym == '$accept' or '|' in sym or ':' in sym:
                continue

            table[current_state][sym] = action
            if re.match(r'^go to state \d+$', action):
                non_terminals.add(sym)
            else:
                terminals.add(sym)

    terminals = sorted(list(terminals))
    non_terminals = sorted(list(non_terminals))

    print("State," + ",".join(terminals + non_terminals))

    for i in sorted(table.keys()):
        row = [str(i)]
        for t in terminals:
            val = table[i].get(t, "")
            if val:
                val = convert_action(val)
            row.append(val)
        for nt in non_terminals:
            val = table[i].get(nt, "")
            if 'go to state' in val:
                val = re.sub(r'go to state ', '', val)
            row.append(val)
        print(",".join(row))

if __name__ == "__main__":
    generate_parsing_table("parser.output")
