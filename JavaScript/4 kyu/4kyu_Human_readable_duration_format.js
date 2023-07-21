function formatDuration(seconds) {
  if (seconds === 0) return "now";
  
  const units = [
    { name: "year", duration: 365 * 24 * 60 * 60 },
    { name: "day", duration: 24 * 60 * 60 },
    { name: "hour", duration: 60 * 60 },
    { name: "minute", duration: 60 },
    { name: "second", duration: 1 }
  ];
  
  return units.reduce((parts, { name, duration }) => {
    if (seconds >= duration) {
      const value = Math.floor(seconds / duration);
      const plural = value > 1 ? "s" : "";
      parts.push(`${value} ${name}${plural}`);
      seconds %= duration;
    }
    return parts;
  }, []).join(", ").replace(/,([^,]*)$/, " and$1");
}