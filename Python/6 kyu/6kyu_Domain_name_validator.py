import re

def validate(domain):
    # Check if the domain contains at least one subdomain apart from TLD
    if '.' not in domain:
        return False

    # Check if the domain is longer than 253 characters
    if len(domain) > 253:
        return False

    # Check if the domain has more than 127 levels
    levels = domain.split('.')
    if len(levels) > 127:
        return False

    # Check each level of the domain
    for level in levels:
        # Check level length
        if len(level) > 63:
            return False

        # Check level format
        if not re.match(r'^[a-zA-Z0-9\-]+$', level):
            return False

        # Check level does not start or end with a hyphen
        if level.startswith('-') or level.endswith('-'):
            return False

    # Check top level (TLD)
    tld = levels[-1]
    if tld.isdigit():
        return False

    return True